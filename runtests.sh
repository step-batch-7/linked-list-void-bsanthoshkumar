rm -rf *.o
gcc -c linkedlist.c

cd test
gcc -c *.c
echo "testing starts...\n"
gcc *.o ../*.o && ./a.out
echo "\n\n...testing ends"
rm -rf ./a.out
rm -rf *.o
cd ../

rm -rf *.o