#!/bin/bash
##
# A bash script to check if a program passes our test cases.
#

# Default homework and source program names.
HW="CST370 Homework"
CPP_SRC="main.cpp"
JAVA_SRC="Main.java"

# Get the homework name
HW=$(basename "$(pwd)")

echo ""
echo "========== Testing $HW =========="

if [[ -f "$CPP_SRC" && -f "$JAVA_SRC" ]]
then
    echo "ERROR:: There are both C++ and Java source files."
    echo "        We need only one source file."
    exit 1
elif [ -f "main.cpp" ]; then
    SRC="$CPP_SRC"
	LANG=CPP
elif [ -f "Main.java" ]
then
    SRC="$JAVA_SRC"
	LANG=Java
else
    echo "ERROR:: source file does not exist."
    exit 1
fi


INPUT=./input/
OUTPUT=./output/
ANSWER=./answer/
MY_RESULT=./my_result/


# Check if test cases exist.
if [ ! -d "$INPUT" ]; then
    echo "$INPUT does not exit."
	exit 1
fi

if [ ! -d "$OUTPUT" ]; then
    echo "$OUTPUT does not exit."
	exit 1
fi

# Number of test cases
NUMS=$(find "$INPUT" -type f -name "*.txt" | wc -l)


# Cleanup previous test results if they exist.
rm -rf main Main.class
rm -rf $ANSWER
rm -rf $MY_RESULT


# Compile the source program
if [ $LANG = "CPP" ]
then
    clang++ -o main -std=c++17 $SRC &> /dev/null
	if ! test -f "main"
	then
		echo "ERROR:: Compilation failed!!!"
 		exit 1
	fi
else
    javac Main.java &> /dev/null
    if ! test -f "Main.class"
	then
		echo "ERROR:: Compilation failed!!!"
 		exit 1
	fi
fi


# Run and test one by one.
cp -r $OUTPUT $ANSWER
mkdir $MY_RESULT

counter=0;
scount=0;
fcount=0;
while [ $counter -lt $NUMS ]
do
    if [ $counter -lt 10 ]
    then
        oname="$OUTPUT/output0$counter.txt"
        aname="$ANSWER/ans0$counter.txt"
        iname="$INPUT/input0$counter.txt"
        rname="$MY_RESULT/result0$counter.txt"
    else
        oname="$OUTPUT/output$counter.txt"
        aname="$ANSWER/ans$counter.txt"
        iname="$INPUT/input$counter.txt"
        rname="$MY_RESULT/result0$counter.txt"

    fi
    cat $oname | tr -d " \t\n\r" > $aname
    
    tname="$MY_RESULT/my_tmp_result.txt"
    rm -f $tname
	
	if [ $LANG = "CPP" ]
	then
		./main < $iname > $tname
	else
        java Main < $iname > $tname
	fi
    
    cat $tname | tr -d " \t\n\r" > $rname
    
    # Compare your result and correct answer
    diff $aname $rname &> /dev/null
    
    PASS=$?
    if [ $PASS -eq 0 ]
    then
        echo "    Test case $counter Passed"
        scount=$((scount+1))
    else
        echo "    Test case $counter Failed"
        fcount=$((fcount+1))
    fi

    counter=$((counter+1))
done

echo "-----------------------"
echo "    $scount PASSED"
echo "    $fcount FAILED"
echo "-----------------------"
echo ""

# Cleanup test results if they exist.
rm -rf main Main.class
rm -rf $ANSWER
rm -rf $MY_RESULT
 
