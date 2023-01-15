#!/bin/bash

TEST_NUMBER="0"
TEST_FILES_DIR="test" #must be inside ./src/
TEST_EXEC_DIR="./test_exec"
LEAKS="0"
LEAKS_STD="0"

function make_test()
{
	echo "Building test : $1"
	export TEST_FILE="$TEST_FILES_DIR/$1"
	if [[ "$1" == *"ignore98"* ]]
	then
		echo "Ignoring std_98 for compilation of test : $1"
		export IGNORE_STD_98="true"
	else
		unset IGNORE_STD_98
	fi
	make ${VERBOSE---quiet}
	TEST_EXEC=$(basename $1 .cpp)
	mv containers ${TEST_EXEC_DIR}/ft/${TEST_EXEC}
	make ${VERBOSE---quiet} std
	mv stdcontainers ${TEST_EXEC_DIR}/std/${TEST_EXEC}
}

function run_test()
{
	echo -n "Running test : $1"
	${TEST_EXEC_DIR}/ft/$1 > ${TEST_EXEC_DIR}/output/$1_ft_stdout 2>${TEST_EXEC_DIR}/output/$1_ft_stderr
	valgrind --leak-check=full --error-exitcode=2 ${TEST_EXEC_DIR}/ft/$1 >/dev/null 2>/dev/null
	LEAKS=$?
	${TEST_EXEC_DIR}/std/$1 > ${TEST_EXEC_DIR}/output/$1_std_stdout 2>${TEST_EXEC_DIR}/output/$1_std_stderr
	valgrind --leak-check=full --error-exitcode=2 ${TEST_EXEC_DIR}/std/$1 >/dev/null 2>/dev/null
	LEAKS_STD=$?
	DIF_STDOUT=$(diff -u ${TEST_EXEC_DIR}/output/$1_ft_stdout ${TEST_EXEC_DIR}/output/$1_std_stdout)
	DIF_STDERR=$(diff -u ${TEST_EXEC_DIR}/output/$1_ft_stderr ${TEST_EXEC_DIR}/output/$1_std_stderr)
	if [ ! -z "$DIF_STDOUT" ]  || [ ! -z "$DIF_STDERR" ]
	then
		RET="1"
	else
		RET="0"
	fi
}

while getopts :f:vs opt
do
	case $opt in

		s)
			echo "Stop on error mode on"
			STOP="1"
		;;
		v)
			echo "Verbose mode on"
			VERBOSE=""
		;;
		f)
			TRY_FILES=$(ls ./src/$TEST_FILES_DIR/*${OPTARG}*)
			if [ ! -z "$TRY_FILES" ]
			then
				for TRY in $TRY_FILES
				do
					RAW_TRY=$(basename $TRY .cpp)
					echo "Adding [${RAW_TRY}] to test list"
					TEST_FILES+=" ${RAW_TRY}.cpp"
					TEST_EXECS+=" ${RAW_TRY}"
				done
			else
				echo "No such file : $OPTARG"
				exit 1
			fi
		;;
		*)
			echo "Wrong option. Choices available are : -v -s -f test_name"
			exit 1
		;;
	esac
done

OPTION_COUNT=`expr $OPTIND - 1`
if [ $OPTION_COUNT -gt 0 ]
then
	echo "`expr $OPTIND - 1` option(s) was/were suplied"
	shift `expr $OPTIND - 1`
	echo "Remaining parameters : $@"
fi

case $1 in

	full)
		echo "Making and running test"
	;&
	make)
		rm -rf $TEST_EXEC_DIR
		echo "Building tests"
		TEST_FILES=${TEST_FILES:-$(ls ./src/$TEST_FILES_DIR)}
		mkdir -p $TEST_EXEC_DIR/ft
		mkdir -p $TEST_EXEC_DIR/std
		for TEST_FILE in $TEST_FILES
		do
			make_test $TEST_FILE
		done
		;&
	run)
		echo "Running tests"
		mkdir -p $TEST_EXEC_DIR/output
		TEST_EXECS=${TEST_EXECS:-$(ls $TEST_EXEC_DIR/ft)}
		for TEST_EXEC in $TEST_EXECS
		do
			run_test $TEST_EXEC
			if [ $RET -ne "0" ]
			then
				echo -en " : \x1b[31mKO\x1b[0m"
				if [ ! -z $STOP ]
				then
					test ! -z "$DIF_STDOUT" && echo "STDOUT DIFF :" && echo "$DIF_STDOUT"
					test ! -z "$DIF_STDERR" && echo "STDERR DIFF :" && echo "$DIF_STDERR"
					break;
				fi
			else
				echo -en " : \x1b[32mOK\x1b[0m"
			fi
			if [ $LEAKS != $LEAKS_STD ]
			then
				echo -e " : \x1b[31mLEAKS\x1b[0m"
				if [ ! -z $STOP ]
				then
					break;
				fi
			else
				echo -e " : \x1b[32mLEAKS OK\x1b[0m"
			fi
		done
	;;
	clean)
		echo "Clearing env and workdir"
		rm -rf $TEST_EXEC_DIR
	;;
	*)
		echo "Usage $0 full | make | run | clean"
		exit 1

	;;
esac
