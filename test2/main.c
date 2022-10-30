#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void OperationClear(char *);

void SetNumber(char *);

void SetOp(char *);

void SetDot(char);

void Round(char *);

LPCTSTR calcNumber(double, double, char);

char resultNumber[30];
HMENU hMenu[18];
HWND hFormula[2];
HINSTANCE hInst;
HFONT hFont;
double number1;
double number2;
char labelBuf[20];
char beforeOp;
char buf[20];
char oper[10] = {0};
int nBtnHeight = 200;

int WINAPI WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        PSTR szCmdLine,
        int iCmdShow
) {
    static TCHAR szClassName[] = TEXT("计算器");  //窗口类名
    HWND hwnd;  //窗口句柄
    MSG msg;  //消息
    WNDCLASS wndclass;  //窗口类

    static HWND hBtn[18];

    HDC hdc;
    int wmId, wmEvent;
    PAINTSTRUCT ps;


    /**********第①步：注册窗口类**********/
    //为窗口类的各个字段赋值
    wndclass.style = CS_HREDRAW | CS_VREDRAW;  //窗口风格
    wndclass.lpfnWndProc = WndProc;  //窗口过程
    wndclass.cbClsExtra = 0;  //暂时不需要理解
    wndclass.cbWndExtra = 0;  //暂时不需要理解
    wndclass.hInstance = hInstance;  //当前窗口句柄
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);  //窗口图标
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);  //鼠标样式
    wndclass.hbrBackground = (HBRUSH) GetStockObject(WHITE_BRUSH);  //窗口背景画刷
    wndclass.lpszMenuName = NULL;  //窗口菜单
    wndclass.lpszClassName = szClassName;  //窗口类名
    //注册窗口
    RegisterClass(&wndclass);
    /*****第②步：创建窗口(并让窗口显示出来)*****/
    hwnd = CreateWindow(
            szClassName,  //窗口类的名字
            TEXT("编写一个计算器"),  //窗口标题（出现在标题栏）
            WS_OVERLAPPEDWINDOW,  //窗口风格
            CW_USEDEFAULT,  //初始化时x轴的位置
            CW_USEDEFAULT,  //初始化时y轴的位置
            800,  //窗口宽度
            600,  //窗口高度
            NULL,  //父窗口句柄
            NULL,  //窗口菜单句柄
            hInstance,  //当前窗口的句柄
            NULL  //不使用该值
    );
    hFont = CreateFont(
            -15/*高度*/, -7.5/*宽度*/, 0, 0, 400 /*一般这个值设为400*/,
            FALSE/*不带斜体*/, FALSE/*不带下划线*/, FALSE/*不带删除线*/,
            DEFAULT_CHARSET,  //使用默认字符集
            OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS,  //这行参数不用管
            DEFAULT_QUALITY,  //默认输出质量
            FF_DONTCARE,  //不指定字体族*/
            TEXT("微软雅黑")  //字体名
    );


    int t = 0;
    for (int i = 0; i < 18; i++) {

        hMenu[i] = (i + 10);
        t++;
        char string[6] = {0};
        itoa(i, string, 10);
        int x = 30 + (150 * t);
        if ((i + 1) % 3 == 0) {
            t = 0;
        }
        int y = nBtnHeight + (i / 3) * 50;

        //创建按钮控件
        if (i == 10) {
            hBtn[i] = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("+/-"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    x /*X坐标*/, y /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,
                    hwnd, (HMENU) (hMenu[i]) /*控件唯一标识符*/, hInstance, NULL
            );
            SendMessage(hBtn[i], WM_SETFONT, (WPARAM) hFont, NULL);//设置按钮字体

        } else if (i == 11) {
            hBtn[i] = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("."),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    x /*X坐标*/, y /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,
                    hwnd, (HMENU) (hMenu[i]) /*控件唯一标识符*/, hInstance, NULL
            );
            SendMessage(hBtn[i], WM_SETFONT, (WPARAM) hFont, NULL);//设置按钮字体

        } else if (i == 12) {//+

            hBtn[i] = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("+"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    x /*X坐标*/, y /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,
                    hwnd, (HMENU) (hMenu[i]) /*控件唯一标识符*/, hInstance, NULL
            );
            SendMessage(hBtn[i], WM_SETFONT, (WPARAM) hFont, NULL);//设置按钮字体
        } else if (i == 13) {//-

            hBtn[i] = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("-"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    x /*X坐标*/, y /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,
                    hwnd, (HMENU) (hMenu[i]) /*控件唯一标识符*/, hInstance, NULL
            );
            SendMessage(hBtn[i], WM_SETFONT, (WPARAM) hFont, NULL);//设置按钮字体
        } else if (i == 14) {//*

            hBtn[i] = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("X"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    x /*X坐标*/, y /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,
                    hwnd, (HMENU) (hMenu[i]) /*控件唯一标识符*/, hInstance, NULL
            );
            SendMessage(hBtn[i], WM_SETFONT, (WPARAM) hFont, NULL);//设置按钮字体
        } else if (i == 15) {//*

            hBtn[i] = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("/"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    x /*X坐标*/, y /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,
                    hwnd, (HMENU) (hMenu[i]) /*控件唯一标识符*/, hInstance, NULL
            );
            SendMessage(hBtn[i], WM_SETFONT, (WPARAM) hFont, NULL);//设置按钮字体
        } else if (i == 16) {//*

            hBtn[i] = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("C"),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    x /*X坐标*/, y /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,
                    hwnd, (HMENU) (hMenu[i]) /*控件唯一标识符*/, hInstance, NULL
            );
            SendMessage(hBtn[i], WM_SETFONT, (WPARAM) hFont, NULL);//设置按钮字体
        } else if (i == 17) {//*

            hBtn[i] = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT("="),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    x /*X坐标*/, y /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,
                    hwnd, (HMENU) (hMenu[i]) /*控件唯一标识符*/, hInstance, NULL
            );
            SendMessage(hBtn[i], WM_SETFONT, (WPARAM) hFont, NULL);//设置按钮字体
        } else {
            hBtn[i] = CreateWindow(
                    TEXT("button"), //按钮控件的类名
                    TEXT(string),
                    WS_CHILD | WS_VISIBLE | WS_BORDER | BS_FLAT/*扁平样式*/,
                    x /*X坐标*/, y /*Y坐标*/, 150 /*宽度*/, 50/*高度*/,
                    hwnd, (HMENU) (hMenu[i]) /*控件唯一标识符*/, hInstance, NULL
            );
            SendMessage(hBtn[i], WM_SETFONT, (WPARAM) hFont, NULL);//设置按钮字体
        }

    }



    //显示窗口
    ShowWindow(hwnd, iCmdShow);
    //更新（绘制）窗口
    UpdateWindow(hwnd);
    /**********第③步：消息循环**********/
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);  //翻译消息
        DispatchMessage(&msg);  //分派消息
    }
    return msg.wParam;
}

/**********第④步：窗口过程**********/
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;  //设备环境句柄
    PAINTSTRUCT ps;
    RECT rect;
    static HFONT hFont2;  //逻辑字体
    static HFONT hFont3;  //逻辑字体
    int wmId, wmEvent;
    switch (message) {

        case WM_CREATE:
            hFont2 = CreateFont(-20/*高*/, -10/*宽*/, 0, 0, 400 /*一般这个值设为400*/,
                                FALSE/*斜体?*/, FALSE/*下划线?*/, FALSE/*删除线?*/, DEFAULT_CHARSET,
                                OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
                                FF_DONTCARE, TEXT("微软雅黑")
            );
            hFont3 = CreateFont(-30/*高*/, -20/*宽*/, 0, 0, 400 /*一般这个值设为400*/,
                                FALSE/*斜体?*/, FALSE/*下划线?*/, FALSE/*删除线?*/, DEFAULT_CHARSET,
                                OUT_CHARACTER_PRECIS, CLIP_CHARACTER_PRECIS, DEFAULT_QUALITY,
                                FF_DONTCARE, TEXT("微软雅黑")
            );
            /**创建算式显示框*/
            hFormula[0] = CreateWindow(TEXT("static"), TEXT(""),
                                       WS_CHILD | WS_VISIBLE  /*边框| WS_BORDER*/ | ES_AUTOHSCROLL /*水平滚动*/ |
                                       ES_RIGHT /*文本右对齐*/,
                                       180 /*x坐标*/, (nBtnHeight - 100) /*y坐标*/, 450 /*宽度*/, 30 /*高度*/,
                                       hwnd /*父窗口句柄*/, (HMENU) 2 /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
            );
            SendMessage(hFormula[0], WM_SETFONT, (WPARAM) hFont2, NULL);

            /**创建结果显示框*/
            hFormula[1] = CreateWindow(TEXT("static"), TEXT(""),
                                       WS_CHILD | WS_VISIBLE /*边框| WS_BORDER */ | ES_AUTOHSCROLL /*水平滚动*/ |
                                       ES_RIGHT /*文本右对齐*/,
                                       180 /*x坐标*/, (nBtnHeight - 70) /*y坐标*/, 450 /*宽度*/, 70 /*高度*/,
                                       hwnd /*父窗口句柄*/, (HMENU) 3 /*控件ID*/, hInst /*当前程序实例句柄*/, NULL
            );
            SendMessage(hFormula[1], WM_SETFONT, (WPARAM) hFont3, NULL);
            break;
            //窗口绘制消息
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);

            EndPaint(hwnd, &ps);
            break;

        case WM_COMMAND:
            wmId = LOWORD(wParam);
            wmEvent = HIWORD(wParam);
            char btnText[2] = {0};

            switch (wmId) {
                case 10:  //按下按钮0
                    itoa(0, btnText, 10);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    SetNumber(btnText);
                    break;
                case 11:  //按下按钮1
                    itoa(1, btnText, 10);
                    SetNumber(btnText);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    break;
                case 12:  //按下按钮2
                    itoa(2, btnText, 10);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    SetNumber(btnText);
                    break;
                case 13:  //按下按钮3
                    itoa(3, btnText, 10);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    SetNumber(btnText);
                    break;
                case 14:  //按下按钮4
                    itoa(4, btnText, 10);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    SetNumber(btnText);
                    break;
                case 15:  //按下按钮5
                    itoa(5, btnText, 10);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    SetNumber(btnText);
                    break;
                case 16:  //按下按钮6
                    itoa(6, btnText, 10);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    SetNumber(btnText);
                    break;
                case 17:  //按下按钮7
                    itoa(7, btnText, 10);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    SetNumber(btnText);
                    break;
                case 18:  //按下按钮8
                    itoa(8, btnText, 10);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    SetNumber(btnText);
                    break;
                case 19:  //按下按钮9
                    itoa(9, btnText, 10);
                    //MessageBox(NULL, TEXT(btnText), TEXT("提示"), MB_OK);
                    SetNumber(btnText);
                    break;
                case 20:  //按下按钮+/-

                    //MessageBox(NULL, TEXT("+/-"), TEXT("提示"), MB_OK);
                    break;
                case 21:  //按下按钮

                    SetDot('.');
                    //MessageBox(NULL, TEXT("."), TEXT("提示"), MB_OK);
                    break;
                case 22:  //按下按钮 +
                    oper[0] = '+';
                    SetOp(&oper);
                    break;
                case 23:  //按下按钮 -
                    oper[0] = '-';
                    SetOp(&oper);
                    break;
                case 24:  //按下按钮 X
                    oper[0] = 'x';
                    SetOp(&oper);
                    break;
                case 25:  //按下按钮 /
                    oper[0] = '/';
                    SetOp(&oper);
                    break;
                case 26:  //按下按钮 C
                    oper[0] = 'C';
                    OperationClear(&oper);
                    break;
                case 27:  //按下按钮 =
                    oper[0] = '=';
                    SetOp(&oper);
                    break;
                default:
                    //不处理的消息一定要交给 DefWindowProc 处理。
                    return DefWindowProc(hwnd, message, wParam, lParam);
            }
            break;
            //窗口销毁消息
        case WM_DESTROY:
            DeleteObject(hFont);
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, message, wParam, lParam);
}

void OperationClear(char *op) {
    if (op[0] == 'C') {
        //MessageBox(NULL, TEXT(op), TEXT("提示"), MB_OK);
        number1 = 0.0;
        number2 = 0.0;
        char result[2] = {0};
        result[0] = ' ';
        SetWindowText(hFormula[0], (LPCTSTR) result);
        SetWindowText(hFormula[1], (LPCTSTR) result);
        memset(buf, 0, 19);
        memset(labelBuf, 0, 19);
        memset(resultNumber, 0, sizeof(resultNumber));

    }

    // return TEXT("Operation");
}

void SetDot(char dot) {
    int len = strlen(&buf);
    if (len > 0) {
        char c = buf[len - 1];
        if (c == '.') {
            return;
        }
    }

    char *p = strchr(&buf, '.');
    if (p != NULL) {
        return;
    }

    double bufNum = atof(&buf);
    if (bufNum > 9999999999.9) {
        return;
    }
    strncat(&buf, &dot, 1);
    strncat(&labelBuf, &dot, 1);
    SetWindowText(hFormula[0], (LPCTSTR) labelBuf);
}

void SetNumber(char *num) {  //10000000000
    double bufNum = atof(&buf);
    if (bufNum > 9999999999.9) {
        return;
    }
    strncat(&buf, num, 1);
    strncat(&labelBuf, num, 1);
    SetWindowText(hFormula[0], (LPCTSTR) labelBuf);
}

void SetOp(char *op) {
    int len = strlen(&labelBuf);
    if (len == 0) {
        return;
    }
    if (len > 0) {
        char c = labelBuf[len - 1];
        if (c == '+' || c == '-' || c == 'x' || c == '/' || c == '=') {
            return;
        }
    }

    if (op[0] == '+' || op[0] == '-' || op[0] == 'x' || op[0] == '/') {
        number1 = atof(&buf);
        beforeOp = op[0];
        memset(buf, 0, sizeof(buf));
    }
    if (op[0] == '=') {
        number2 = atof(&buf);
        LPCTSTR ret = calcNumber(number1, number2, beforeOp);
        SetWindowText(hFormula[1], ret);
        memset(resultNumber, 0, sizeof(resultNumber));

    }
    strncat(&labelBuf, op, 1);
    SetWindowText(hFormula[0], (LPCTSTR) labelBuf);
    if (op[0] == '=') {
        number1 = 0.0;
        number2 = 0.0;
        memset(buf, 0, sizeof(buf));
        memset(labelBuf, 0, sizeof(labelBuf));
        SetWindowText(hFormula[0], (LPCTSTR) labelBuf);

    }
    // char lenStr[5] = {0};
    //itoa(len,lenStr,10);
    //MessageBox(NULL, TEXT(lenStr), TEXT("提示"), MB_OK);
}

LPCTSTR calcNumber(double n1, double n2, char op) {
    //MessageBox(NULL, TEXT("2222"), TEXT("提示"), MB_OK);
    if (op == '+') {
        double n = n1 + n2;
        memset(resultNumber, 0, sizeof(resultNumber));
        snprintf(resultNumber, 11, "%.12f", n);
        Round(resultNumber);
        return (LPCTSTR) resultNumber;
    }
    if (op == '-') {
        double n = n1 - n2;
        memset(resultNumber, 0, sizeof(resultNumber));
        snprintf(resultNumber, 11, "%.12f", n);
        Round(resultNumber);
        return (LPCTSTR) resultNumber;
    }
    if (op == 'x') {
        double n = n1 * n2;
        memset(resultNumber, 0, sizeof(resultNumber));
        snprintf(resultNumber, 11, "%.12f", n);
        Round(resultNumber);
        return (LPCTSTR) resultNumber;
    }
    if (op == '/') {
        double n;
        if (n2 == 0) {
            n = 0;
        } else {
            n = n1 / n2;
        }

        memset(resultNumber, 0, sizeof(resultNumber));
        snprintf(resultNumber, 11, "%.12f", n);
        Round(resultNumber);
        return (LPCTSTR) resultNumber;
    }
    return (LPCTSTR) resultNumber;
}

void Round(char *resultStr) {
    int length = strlen(resultStr);
    int m = length - 1;
    int k = 0;
    do {
        if (resultStr[m] == '.') {
            k = m;
            break;
        }
        if (resultStr[m] != '0') {
            break;
        }
        if (resultStr[m] == '0') {
            resultStr[m] = '\0';
        }
        m--;
    } while (m > 0);
    if (k == strlen(resultStr) - 1) {
        resultStr[k] = '\0';
    }

}