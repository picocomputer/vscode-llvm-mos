#include <rp6502.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void *argv_mem(size_t size) { return malloc(size); }

// int main(int argc, char *argv[])
// {
//     puts("Hello from LLVM-MOS");
//     printf("argc: %d\n", argc); 
//     for (int i = 0; i < argc; i++) {
//         printf("argv[%d]: %s\n", i, argv[i]);
//     }
// }
 
// int main(int argc, char *argv[])
// {
//     int i;

//     printf("argc = %d\n", argc);
//     for (i = 0; i < argc; i++)
//         printf("argv[%d] = %s\n", i, argv[i]);

//     if (argc == 2)
//     {
//         printf("Success\n");
//         return 0;
//     }

//     if (argc == 1)
//     {
//         char arg[] = "Foo";
//         printf("Executing self with arg: %s\n", arg);
//         ria_execl(argv[0], arg, NULL);
//     }

//     // The argv memory can be reclaimed.
//     // (not useful here in the example)
//     free(argv);
//     return 1;
// }





static void print_time(time_t time)
{
    char buf[100];
    struct tm *tminfo;

    tminfo = gmtime(&time);
    strftime(buf, sizeof(buf), "UTC  : %c", tminfo);
    puts(buf);

    tminfo = localtime(&time);
    strftime(buf, sizeof(buf), "Local: %c %Z", tminfo);
    puts(buf);
}

void main()
{
    puts("This requires RP6502-RIA v0.16 or later.");

    puts("\nThe current time is:");
    print_time(time(NULL));

    puts("\nThis example is standard time:");
    print_time(1735732800); // 1-JAN-2025 noon UTC

    puts("\nDaylight savings time, if observed:");
    print_time(1751371200); // 1-JUL-2025 noon UTC
}
