#include "functions.cpp"

using namespace std;

int main(int argc, char *argv[], int wutdo)
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    wutdo = 1;
    if(argc > 1)
    {
        for(int n = 1; n < argc; n++)
        {
            if(strstr(argv[n], "art")) {
                wutdo = 2;
            }
            if(strstr(argv[n], "help")) {
                wutdo = 0;
            }
        }
    }

    switch(wutdo)
    {
    case 0:
        printf("Developers: \n");
        writeColor(red, "	Ruben R(Rdogg) - Main developer [!RRuben4Rig]\n");
        writeColor(lblue, "	Chris S(Someguy123) - Secondary developer [!b/cd2dRON OR SomeFagp/.]\n");
        break;

    case 1:
        printf("                         ");
        writeColor(red, "%s", PrintSystemName());
        writeColor(white, "\@");
        writeColor(lblue, "%s", PrintUserName());
        printf("\n");
        writeColor(red, "       _.-;");
        writeColor(green, ";-._          ");
        PrintSystemUpTime();
        printf("\n");
        writeColor(red, "'-..-'|   |");
        writeColor(green, "|   |         ");
        PrintMonitorResolution();
        printf("\n");
        writeColor(red, "'-..-'|_.-;");
        writeColor(green, ";-._|         ");
        PrintOSInfo();
        printf("\n");
        writeColor(blue, "'-..-'|   |");
        writeColor(yellow, "|   |         ");
        PrintKernelInfo();
        printf("\n");
        writeColor(blue, "'-..-'|_.-'");
        writeColor(yellow, "'-._|         ");
        SetConsoleTextAttribute(hConsole, normal);
        PrintMemoryInfo();
        printf("\n                         ");
        getDriveInfo();
        printf("\n                         ");
        PrintVideoInfo();
        printf("\n                         ");
        PrintProcessorInfo();
        printf("\n                         ");
        break;

    case 2:
        writeColor(red, "        ,.=:!!t3Z3z.,               ");
        writeColor(red, "		%s", PrintSystemName());
        writeColor(white, "\@");
        writeColor(lblue, "%s", PrintUserName());
        printf("\n");
        writeColor(red, "       :tt:::tt333EE3                	");
        PrintSystemUpTime();
        printf("\n");
        writeColor(red, "       Et:::ztt33EEE");
        writeColor(green, " @Ee.,      ..,	");
        PrintMonitorResolution();
        printf("\n");
        writeColor(red, "      ;tt:::tt333EE7 ");
        writeColor(green, ";EEEEEEttttt33#	");
        PrintOSInfo();
        printf("\n");
        writeColor(red, "     :Et:::zt333EEQ. ");
        writeColor(green, "SEEEEEttttt33QL	");
        PrintKernelInfo();
        printf("\n");
        writeColor(red, "     it::::tt333EEF ");
        writeColor(green, "@EEEEEEttttt33F 	");
        PrintMemoryInfo();
        printf("\n");
        writeColor(red, "    ;3-*````'*4EEV ");
        writeColor(green, ":EEEEEEttttt33@. 	");
        getDriveInfo();
        printf("\n");
        writeColor(blue, "    ,.=::::!t=., ");
        writeColor(red, "` ");
        writeColor(green, "@EEEEEEtttz33QF  	");
        PrintVideoInfo();
        printf("\n");
        writeColor(blue, "   ;::::::::zt33)   ");
        writeColor(green, "'4EEEtttji3P*   	");
        PrintProcessorInfo();
        printf("\n");
        writeColor(blue, "  :t::::::::tt33.");
        writeColor(yellow, ":Z3z..  ");
        writeColor(green, "``");
        writeColor(yellow, ",..g.   \n");
        writeColor(blue, "  i::::::::zt33F");
        writeColor(yellow, "AEEEtttt::::ztF  \n");
        writeColor(blue, "  ;:::::::::t33V ");
        writeColor(yellow, ";EEEttttt::::t3     \n");
        writeColor(blue, " E::::::::zt33L ");
        writeColor(yellow, "@EEEtttt::::z3F    \n");
        writeColor(blue, "{3-*````'*4E3) ");
        writeColor(yellow, ";EEEtttt:::::tZ`     \n");
        writeColor(blue, "            `");
        writeColor(yellow, ":EEEEtttt::::z7       \n");
        writeColor(yellow, "                'VEzjt:;;z/*`\n\n");
        break;
    }
    return 0;
}