//Calculator_GUI.cpp
// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c
//#include <winapifamily.h>
//#include <winmm.lib>
//#include <iostream>
//#include <chrono>
//#include <mmsystem.h>
//#include <Mmsystem.h>
//#include <windowsx.h>
//#include <assert.h>
//#include <commctrl.h>
//#include <thread>
#include <windows.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <string>
#include <atlstr.h>
#include <math.h>
using namespace std;
HWND button0;
HWND button1;
HWND button2;
HWND button3;
HWND button4;
HWND button5;
HWND button6;
HWND button7;
HWND button8;
HWND button9;
HWND EQUAL_BUT;

HWND CLEAR;

HWND PLUS_SIGN;
HWND MINUS_SIGN;
HWND DIV_SIGN;
HWND MUL_SIGN;

HWND DEC_SIGN;

HWND BACK;

HWND CK_BOX_DEC;
//Buttons
#define LBut                  0x0201
#define RBut                  0x0002
#define btn0_ID 5000
#define btn1_ID 5100
#define btn2_ID 5200
#define btn3_ID 5300
#define btn4_ID 5400
#define btn5_ID 5500
#define btn6_ID 5600
#define btn7_ID 5700
#define btn8_ID 5800
#define btn9_ID 5900
#define btn_equal_ID 6000
#define btn_plus_ID 6100
#define btn_minus_ID 6200
#define btn_mul_ID 6300
#define btn_div_ID 6400
#define btn_clear_ID 6500
#define btn_back_ID 6600
#define btn_dec_ID 6700

#define ck_btn_dec_ID 6800

//Keys
//letters
/*#define key_a 0x41
#define key_b 0x42
#define key_c 0x43
#define key_d 0x44
#define key_e 0x45
#define key_f 0x46
#define key_g 0x47
#define key_h 0x48
#define key_i 0x49
#define key_j 0x4a
#define key_k 0x4b
#define key_l 0x4c
#define key_m 0x4d
#define key_n 0x4e
#define key_o 0x4f
#define key_p 0x50
#define key_q 0x51
#define key_r 0x52
#define key_s 0x53
#define key_t 0x54
#define key_u 0x55
#define key_v 0x56
#define key_w 0x57
#define key_x 0x58
#define key_y 0x59
#define key_z 0x5a

//not letters or numbers
#define key_SPACE 0x20
#define key_shift 0x10*/
#define key_back 0x8

//numbers
#define key_0 0x30
#define key_1 0x31
#define key_2 0x32
#define key_3 0x33
#define key_4 0x34
#define key_5 0x35
#define key_6 0x36
#define key_7 0x37
#define key_8 0x38
#define key_9 0x39

//Operators
#define key_dec 0xbe





// Global variables
// The main window class name.
static TCHAR szWindowClass[] = _T("DesktopApp");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("C̵̢̈̽a̵͎͋ḷ̴̆c̴͓͝u̶̼̎̿l̶̡̔ă̸͉͠t̸̡̑o̸̹͆r̶̪̾");

static string num__1;
static string num__2;
static string RESULT = "NULL";
static string previous_result = "NULL";

bool result_display = false;

static bool box_toggle = false;

static char oper; //+ - / *... operators

static double num_1 = 0;
static double num_2 = 0;
static double RESULT_NUM = 0;

static enum NUM_IDE {
    first,
    second
};

NUM_IDE n = first;

class CALCULATOR {
public:
   

    void add(int val, string str, HWND hWnd) {
        string current_num;
        if (n == first) {
            current_num = num__1;
        }
        else {
            current_num = num__2;
        }
        if (str.length() + 1 == 25 || current_num.length() + 1 == 10) {
            if (MessageBox(hWnd, L"overload", L"C̸̗͛͋a̵̢͉͑͛̈l̵̯̃̽̓͘c̷̛̯̱̠̳̻̐͒͛̈́̈ŭ̴̡̡̻͈͇̀͐̄l̵̛̛̮͉̓̈́̀a̶̞̼̱͊͊t̴̛̻̝͎͖͗o̷͙̝̐͝ͅr̶̛̰̉͊͋̀", MB_OKCANCEL) == IDOK)
            {

            }

        }
        else {
            if (n == first) {
                num__1 = num__1 + to_string(val);
                result_display = false;
            }
            else {
                num__2 = num__2 + to_string(val);
                result_display = false;
            }

        };
    }

    void set_op(HWND hWnd, char op, string str) {
        if (num__1.length() + 1 == 25 || str.length() + 1 == 25) {
            if (MessageBox(hWnd, L"overload", L"C̸̗͛͋a̵̢͉͑͛̈l̵̯̃̽̓͘c̷̛̯̱̠̳̻̐͒͛̈́̈ŭ̴̡̡̻͈͇̀͐̄l̵̛̛̮͉̓̈́̀a̶̞̼̱͊͊t̴̛̻̝͎͖͗o̷͙̝̐͝ͅr̶̛̰̉͊͋̀", MB_OKCANCEL) == IDOK)
            {

            }
        }
        else {
            if (n == first) {
                oper = op;
                result_display = false;
                n = second;
            }

        };

        InvalidateRect(hWnd, 0, TRUE);
    }

    void clear() {
        num_1 = 0;
        num_2 = 0;

        num__1 = "";
        num__2 = "";

        oper = ' ';

        RESULT_NUM = 0;

        n = first;
    }

    void cal_res() {
       
        try {
            num_1 = stod(num__1);
            num_2 = stod(num__2);
            switch (oper) {
            case '+':
                RESULT_NUM = num_1 + num_2;
                break;

            case '-':
                RESULT_NUM = num_1 - num_2;
                break;

            case '*':
                RESULT_NUM = num_1 * num_2;
                break;

            case '/':
                if (num_1 == 0 || num_2 == 0) {
                    RESULT_NUM = 0;
                }
                else {
                    RESULT_NUM = num_1 / num_2;
                }                
                break;

            default:
                break;
            }

            previous_result = RESULT;
            RESULT = to_string(RESULT_NUM);

            if (RESULT.length() == 24) {
                RESULT = RESULT.substr(0, 24);
            }

            //Remove Trailing zeros
            RESULT.erase(RESULT.find_last_not_of('0') + 1, std::string::npos);

            if (box_toggle == true) {
                RESULT = to_string(stoi(to_string(round(stod(RESULT)))));
            }
            

        }
        catch (int err) {
            RESULT = "OVERLOAD";
        }

        clear();

    }
    
    void render_all(HWND hWnd) {        

        CK_BOX_DEC = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"Round Decimal?",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, // Styles
            320,        // x position 
            40,         // y position 
            140,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)ck_btn_dec_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button1 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"1",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            10,        // x position 
            40,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn1_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button2 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"2",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            60,        // x position 
            40,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn2_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button3 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"3",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            110,        // x position 
            40,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn3_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button4 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"4",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            10,        // x position 
            90,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn4_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button5 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"5",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            60,        // x position 
            90,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn5_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button6 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"6",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            110,        // x position 
            90,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn6_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button7 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"7",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            10,        // x position 
            140,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn7_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button8 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"8",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            60,        // x position 
            140,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn8_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button9 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"9",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            110,        // x position 
            140,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn9_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        button0 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"0",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            60,        // x position 
            190,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn0_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        EQUAL_BUT = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"=",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            10,        // x position 
            190,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn_equal_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        PLUS_SIGN = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"+",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            10,        // x position 
            240,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn_plus_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        DEC_SIGN = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L".",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            60,        // x position 
            240,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn_dec_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        MINUS_SIGN = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"-",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            10,        // x position 
            290,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn_minus_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        MUL_SIGN = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"X",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            10,        // x position 
            340,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn_mul_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        DIV_SIGN = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"/",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            10,        // x position 
            390,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn_div_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        CLEAR = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"CE",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            160,        // x position 
            40,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn_clear_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed

        BACK = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed
            L"<-    BACK",        // Text will be defined later
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles
            210,        // x position 
            40,         // y position 
            100,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            (HMENU)btn_back_ID,       // No menu
            (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
            NULL);      // Pointer not needed
    }
    
};


HINSTANCE hInst;
// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int CALLBACK WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Window Template"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindow explained:
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application does not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 500,
        NULL,
        NULL,
        hInstance,
        NULL
    );    
    
    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Window Template"),
            NULL);

        return 1;
    }
    CALCULATOR().render_all(hWnd);
    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}



//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    wchar_t msg[32];
    string current_num;
    PAINTSTRUCT ps;
    HDC hdc;
    int coord_x = 5;
    int coord_y = 5;
    //TCHAR res[] = _T("Result: ");

    string place = "Previous Result: " + previous_result;//to_string(num__1.length());//to_string(num_1);
    string re = place;//"Bruh";//to_string(CALCULATOR().num_1);
    TCHAR pres[50];//{ (TCHAR)num.c_str() };//_T(" ");
    _tcscpy_s(pres, CA2T(re.c_str()));    


    string placehold = num__1 + oper + num__2;//to_string(num__1.length());//to_string(num_1);
    string num = placehold;//"Bruh";//to_string(CALCULATOR().num_1);
    TCHAR text[50];//{ (TCHAR)num.c_str() };//_T(" ");
    _tcscpy_s(text, CA2T(num.c_str()));


    string placehold2 = "Result: " + RESULT;//to_string(num__1.length());//to_string(num_1);
    string result_p = placehold2;//"Bruh";//to_string(CALCULATOR().num_1);
    TCHAR res_t[50];//{ (TCHAR)num.c_str() };//_T(" ");
    _tcscpy_s(res_t, CA2T(result_p.c_str()));
    

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
          
       
            TextOut(hdc,
                5, 5,
                text, _tcslen(text));

            TextOut(hdc,
                190, 200,
                res_t, _tcslen(res_t));           
        
        // Here your application is laid out.
        // For this introduction, we just print out "Hello, Windows desktop!"
        // in the top left corner.
        //Draws moving text in different places
        /*TextOut(hdc,
            coord_x, coord_y,
            text, _tcslen(text));*/
        // End application-specific layout section.

        /*TextOut(hdc,
            140, 200,
            res, _tcslen(res));*/
        //previous result
            TextOut(hdc,
                120, 230,
                pres, _tcslen(pres));


            EndPaint(hWnd, &ps);
            
        
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    case WM_KEYDOWN:
        //equals
        

        // + key
        if (GetAsyncKeyState(VK_OEM_PLUS) && GetAsyncKeyState(VK_SHIFT)) {
            CALCULATOR().set_op(hWnd, '+', placehold);
        }
        else if (GetAsyncKeyState(VK_OEM_PLUS) || GetAsyncKeyState(VK_RETURN)) {
            if (n == second && num__2 != "") {
                result_display = true;
                CALCULATOR().cal_res();
                InvalidateRect(hWnd, 0, TRUE);
            }
        }
        // - key
        else if (GetAsyncKeyState(VK_OEM_MINUS))
        {
            CALCULATOR().set_op(hWnd, '-', placehold);
        }
        // * key
        else if (GetAsyncKeyState('8') && GetAsyncKeyState(VK_SHIFT))
        {
            CALCULATOR().set_op(hWnd, '*', placehold);
        }
        //Divide
        else if (GetAsyncKeyState(VK_OEM_2))
        {
            CALCULATOR().set_op(hWnd, '/', placehold);
        }
        
        else {


            switch (wParam) {
            case key_1:
                CALCULATOR().add(1, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_2:
                CALCULATOR().add(2, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_3:
                CALCULATOR().add(3, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_4:
                CALCULATOR().add(4, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_5:
                CALCULATOR().add(5, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_6:
                CALCULATOR().add(6, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_7:
                CALCULATOR().add(7, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_8:
                CALCULATOR().add(8, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_9:
                CALCULATOR().add(9, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_0:
                CALCULATOR().add(0, placehold, hWnd);
                InvalidateRect(hWnd, 0, TRUE);
                break;

            case key_dec:
                if (n == first) {
                    current_num = num__1;
                }
                else {
                    current_num = num__2;
                }
                if (placehold.length() + 1 == 25 || current_num.length() + 1 == 10) {
                    if (MessageBox(hWnd, L"overload", L"C̸̗͛͋a̵̢͉͑͛̈l̵̯̃̽̓͘c̷̛̯̱̠̳̻̐͒͛̈́̈ŭ̴̡̡̻͈͇̀͐̄l̵̛̛̮͉̓̈́̀a̶̞̼̱͊͊t̴̛̻̝͎͖͗o̷͙̝̐͝ͅr̶̛̰̉͊͋̀", MB_OKCANCEL) == IDOK)
                    {

                    }

                }
                else {
                    if (n == first) {
                        num__1 = num__1 + ".";
                        result_display = false;
                    }
                    else {
                        num__2 = num__2 + ".";
                        result_display = false;
                    }

                };
                InvalidateRect(hWnd, 0, TRUE);
                break;
            case key_back:
                if (n == first) {
                    int l = num__1.length();
                    num__1 = num__1.substr(0, (l - 1));
                }
                else if (n == second && num__2 == "") {
                    oper = ' ';
                    n = first;
                }
                else {
                    int l = num__2.length();
                    num__2 = num__2.substr(0, (l - 1));
                }
                InvalidateRect(hWnd, 0, TRUE);
                break;

            default:
                break;
            }

            //swprintf_s(msg, L"WM_KEYDOWN: 0x%x\n", wParam);
            //OutputDebugString(msg);
        }

       
        break;
        

    case WM_CLOSE:
        if (MessageBox(hWnd, L"Really quit?", L"C̸̗͛͋a̵̢͉͑͛̈l̵̯̃̽̓͘c̷̛̯̱̠̳̻̐͒͛̈́̈ŭ̴̡̡̻͈͇̀͐̄l̵̛̛̮͉̓̈́̀a̶̞̼̱͊͊t̴̛̻̝͎͖͗o̷͙̝̐͝ͅr̶̛̰̉͊͋̀", MB_OKCANCEL) == IDOK)
        {
            DestroyWindow(hWnd);
        }
        else {
                        
            InvalidateRect(hWnd, 0, TRUE);
        }
        break;

    case WM_COMMAND:
        switch (wParam) {
        
        case btn1_ID:     
            CALCULATOR().add(1, placehold, hWnd);                   
            InvalidateRect(hWnd, 0, TRUE);
            break;        

        case btn2_ID:
            CALCULATOR().add(2, placehold, hWnd);                        
            InvalidateRect(hWnd, 0, TRUE);

            break;

        case btn3_ID:
            CALCULATOR().add(3, placehold, hWnd);
                      
            InvalidateRect(hWnd, 0, TRUE);

            break;


        case btn4_ID:
            CALCULATOR().add(4, placehold, hWnd);
                  
            InvalidateRect(hWnd, 0, TRUE);

            break;

        case btn5_ID:
            CALCULATOR().add(5, placehold, hWnd);
                        InvalidateRect(hWnd, 0, TRUE);

            break;

        case btn6_ID:
            CALCULATOR().add(6, placehold, hWnd);
            
            InvalidateRect(hWnd, 0, TRUE);

            break;

        case btn7_ID:
            CALCULATOR().add(7, placehold, hWnd);
            
            InvalidateRect(hWnd, 0, TRUE);

            break;

        case btn8_ID:
            CALCULATOR().add(8, placehold, hWnd);
            InvalidateRect(hWnd, 0, TRUE);

            break;

        case btn9_ID:
            CALCULATOR().add(9, placehold, hWnd);           
            InvalidateRect(hWnd, 0, TRUE);
            break;

        case btn0_ID:
            CALCULATOR().add(0, placehold, hWnd);    
            InvalidateRect(hWnd, 0, TRUE);
            break;

        case btn_equal_ID:
            if (n == second && num__2 != "") {
                result_display = true;
                CALCULATOR().cal_res();
                InvalidateRect(hWnd, 0, TRUE);
            }            
            break;

        case btn_plus_ID:
            CALCULATOR().set_op(hWnd, '+', placehold);
            break;

        case btn_dec_ID:            
            if (n == first) {
                current_num = num__1;
            }
            else {
                current_num = num__2;
            }
            if (placehold.length() + 1 == 25 || current_num.length() + 1 == 10) {
                if (MessageBox(hWnd, L"overload", L"C̸̗͛͋a̵̢͉͑͛̈l̵̯̃̽̓͘c̷̛̯̱̠̳̻̐͒͛̈́̈ŭ̴̡̡̻͈͇̀͐̄l̵̛̛̮͉̓̈́̀a̶̞̼̱͊͊t̴̛̻̝͎͖͗o̷͙̝̐͝ͅr̶̛̰̉͊͋̀", MB_OKCANCEL) == IDOK)
                {

                }

            }
            else {
                if (n == first) {
                    num__1 = num__1 + ".";
                    result_display = false;
                }
                else {
                    num__2 = num__2 + ".";
                    result_display = false;
                }

            };
            InvalidateRect(hWnd, 0, TRUE);
            break;

        case btn_minus_ID:
            CALCULATOR().set_op(hWnd, '-', placehold);
            break;

        case btn_mul_ID:
            CALCULATOR().set_op(hWnd, '*', placehold);
            break;

        case btn_div_ID:
            CALCULATOR().set_op(hWnd, '/', placehold);
            break;

        case btn_clear_ID:
            CALCULATOR().clear();                        
            InvalidateRect(hWnd, 0, TRUE);
            break;

        case ck_btn_dec_ID:
            if (box_toggle == true) {
                box_toggle = false;
            }

            else if (box_toggle == false) {
                box_toggle = true;
            }
            break;

        case btn_back_ID:
            if (n == first) {
                int l = num__1.length();
                num__1 = num__1.substr(0, (l - 1));
            }
            else if (n == second && num__2 == "") {
                oper = ' ';
                n = first;
            }

            else {
                int l = num__2.length();
                num__2 = num__2.substr(0, (l - 1));
            }
            InvalidateRect(hWnd, 0, TRUE);
            break;        
        }
        SetFocus(hWnd);
        break;

    case LBut:
        //Mouse Left
        /*if (MessageBox(hWnd, L"Left Mouse Button Click!", L"My application", MB_OKCANCEL) == IDOK)
            break;*/
        break;

    case WM_RBUTTONDOWN:
        //Mouse Right
        /*if (MessageBox(hWnd, L"Right Mouse Button Click!", L"My application", MB_OKCANCEL) == IDOK)
            break;*/
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    //cout << "Bruh" << endl;
    return 0;
}