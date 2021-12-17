set -xue

echo 0123456789 > test1
seq 1 1000 | tr -d '\n' > test2
seq 1 10 | grep -o $ > test3
seq 100 0 > test4
seq 0 50 > test5

file1=./../get_next_line.c
file2=./../get_next_line_utils.c
file3=main.c
tmp=leaks.c
# tmp="-fsanitize=address -fsanitize=undefined"

gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=5 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=2147483647 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test2
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=9 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=11 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=10 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test3
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test4
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test5


file1=./../get_next_line_bonus.c
file2=./../get_next_line_utils_bonus.c
file3=main_bonus.c


echo "Test Bonus"

gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=5 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=2147483647 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test2
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=9 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=11 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=10 && ./a.out test1
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test3
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test4
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test5

gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test5 test4
gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test4 test5

gcc -Wall -Werror -Wextra $file1 $file2 $file3 $tmp -D BUFFER_SIZE=1024 && ./a.out test4 testaaaaaaaaaaaa
