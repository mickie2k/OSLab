for file in $(find . -type f -name "*.c")
do
    #trimmedName=`echo $file|cut -d'/' -f2`
    trimmedName=`echo $file | cut -d'/' -f2 | cut -d'.' -f1` 

    gcc -o $trimmedName $file 2> /dev/null
    if [ -f $trimmedName  ]
    then
        ans2=$(./$trimmedName)
        if [ $ans2 = 20 ] 
        then
            ans=10
        else
            ans=7
        fi
        
    else
        ans=5
    fi
    printf "%s %s\n" $trimmedName $ans

done 