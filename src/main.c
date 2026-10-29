#include <stdio.h>
#include <stdlib.h>
#include "../include/affine_cipher.h"
#include "../include/mathematics.h"
#include "../include/misc.h"
#include "../include/mcq.h"
#include "../include/tf.h"
#include "../include/blank.h"
#include "../include/ui.h"
#include "../include/auth.h"
#include "../include/stud_menu.h"
#include "../include/teacher_menu.h"

int main(void)
{
    while (1)
    {
        clear_screen();
        print_banner();
        print_main_menu();

        int main_menu_opt = 0;
        printf("Enter option (1/2/3/4): ");
        if (scanf("%d", &main_menu_opt) != 1)
        {
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch (main_menu_opt)
        {
        case STUD_MENU:
        {
            StudentLoginDta student;
            clear_screen();
            print_banner();
            print_divider('-',52);
            printf("                   STUDENT LOGIN                   \n");
            print_divider('-', 52);

            if (student_login(&student))
            {
                printf("\nPress Enter to enter Student Dashboard...");
                getchar();
                handle_stud_menu(&student);
            }
            else
            {
                printf("\nPress Enter to return to main menu...");
                getchar();
            }
            break;
        }
        case TEACHER_MENU:
        {
            TeacherLoginDta teacher;
            clear_screen();
            print_banner();
            print_divider('-', 52);
            printf("                   TEACHER LOGIN                   \n");
            print_divider('-', 52);

            if (teacher_login(&teacher))
            {
                printf("\nPress Enter to enter Teacher Dashboard...");
                getchar();
                handle_teacher_menu(&teacher);
            }
            else
            {
                printf("\nPress Enter to return to main menu...");
                getchar();
            }
            break;
        }
        case ADMIN_MENU:
        {
            clear_screen();
            print_banner();
            print_divider('-', 52);
            printf("                    ADMIN LOGIN                    \n");
            print_divider('-', 52);

            if (admin_login())
            {
                printf("\nPress Enter to enter Admin Dashboard...");
                getchar();
                handle_admin_menu();
            }
            else
            {
                printf("\nPress Enter to return to main menu...");
                getchar();
            }
            break;
        }
        case EXIT_MAIN_MENU:
        {
            clear_screen();
            print_banner();
            printf("\033[32mThank you for using Quiz-Core. Goodbye!\033[0m\n\n");
            return 0;
        }
        default:
            printf("Invalid option. Press Enter to continue...\n");
            getchar();
            break;
        }
    }
}
