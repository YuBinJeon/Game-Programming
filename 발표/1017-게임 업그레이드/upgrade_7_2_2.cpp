/*
 * ========================================
 *   🎮 100을 넘어라 게임 (업그레이드 버전)
 * ========================================
 * 개발: 2025 업그레이드 버전
 * 컴파일: gcc -O2 -Wall upgrade_7_2_2.cpp -o upgrade_7_2_2.exe
 * 실행: upgrade_7_2_2.exe [--demo]
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// ========== 전역 상수 ==========
#define TARGET_SCORE 100
#define MIN_INPUT 1
#define MAX_INPUT 10
#define BAR_LENGTH 20

// 콘솔 색상 코드
#define COLOR_DEFAULT 7
#define COLOR_TITLE 14      // 노란색
#define COLOR_PLAYER 10     // 초록색
#define COLOR_COMPUTER 11   // 하늘색
#define COLOR_WARNING 12    // 빨간색
#define COLOR_SUCCESS 10    // 초록색

// ========== 함수 선언 ==========
void setColor(int color);
void clearScreen();
void playSound(int freq, int duration);
void intro();
int showMenu();
void showRules();
void drawProgressBar(int current, int max);
int getPlayerInput(int usedNumbers[], int usedCount);
int getComputerInput(int usedNumbers[], int usedCount, int lastPlayerInput, int difficulty);
void showWinner(int isPlayer);
void saveRecord(int isPlayer);
void gameLoop(int difficulty);
void demoMode();

// ========== 유틸리티 함수 ==========

// 콘솔 색상 변경
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// 화면 지우기
void clearScreen() {
    system("cls");
}

// 사운드 출력
void playSound(int freq, int duration) {
    Beep(freq, duration);
}

// ========== 인트로 화면 ==========
void intro() {
    clearScreen();
    setColor(COLOR_TITLE);
    
    // ASCII 아트 타이틀 (점멸 효과)
    for(int blink = 0; blink < 3; blink++) {
        clearScreen();
        printf("\n");
        printf("  ██╗ ██████╗  ██████╗     ██╗\n");
        printf(" ███║██╔═████╗██╔═████╗   ███║\n");
        printf(" ╚██║██║██╔██║██║██╔██║   ╚██║\n");
        printf("  ██║████╔╝██║████╔╝██║    ██║\n");
        printf("  ██║╚██████╔╝╚██████╔╝    ██║\n");
        printf("  ╚═╝ ╚═════╝  ╚═════╝     ╚═╝\n");
        printf("\n");
        setColor(COLOR_DEFAULT);
        printf("        🎯 100을 넘어라 게임 🎯\n");
        printf("     ═══════════════════════════\n\n");
        
        if(blink < 2) {
            Sleep(300);
            clearScreen();
            Sleep(200);
        }
    }
    
    // 시작 사운드
    playSound(523, 150);  // C
    playSound(659, 150);  // E
    playSound(784, 200);  // G
    
    setColor(COLOR_SUCCESS);
    printf("\n       Press any key to start...\n");
    setColor(COLOR_DEFAULT);
    
    _getch();
}

// ========== 메뉴 시스템 ==========
int showMenu() {
    int choice;
    
    clearScreen();
    setColor(COLOR_TITLE);
    printf("\n");
    printf("  ╔════════════════════════════════╗\n");
    printf("  ║     🎮 100을 넘어라 게임 🎮     ║\n");
    printf("  ╚════════════════════════════════╝\n\n");
    setColor(COLOR_DEFAULT);
    
    printf("  1️⃣  게임 시작 (Easy Mode)\n");
    printf("  2️⃣  게임 시작 (Hard Mode)\n");
    printf("  3️⃣  게임 규칙 설명\n");
    printf("  4️⃣  게임 종료\n\n");
    printf("  선택: ");
    
    scanf("%d", &choice);
    playSound(800, 50);
    
    return choice;
}

// ========== 규칙 설명 ==========
void showRules() {
    clearScreen();
    setColor(COLOR_TITLE);
    printf("\n  📜 게임 규칙 📜\n");
    printf("  ═══════════════════════════════════\n\n");
    setColor(COLOR_DEFAULT);
    
    printf("  ▶ 플레이어와 컴퓨터가 번갈아가며 숫자를 선택합니다.\n");
    printf("  ▶ 선택 가능한 숫자: 1 ~ 10\n");
    printf("  ▶ 한 번 선택한 숫자는 다시 선택할 수 없습니다.\n");
    printf("  ▶ 누적 합계가 100을 넘으면 그 턴의 플레이어가 승리!\n\n");
    
    setColor(COLOR_PLAYER);
    printf("  [Easy Mode] 컴퓨터가 랜덤으로 선택\n");
    setColor(COLOR_COMPUTER);
    printf("  [Hard Mode] 컴퓨터가 전략적으로 선택\n\n");
    setColor(COLOR_DEFAULT);
    
    printf("  Press any key to continue...");
    _getch();
}

// ========== 진행 막대 그리기 ==========
void drawProgressBar(int current, int max) {
    int filled = (current * BAR_LENGTH) / max;
    
    printf("  누적합: %d / %d\n  ", current, max);
    
    setColor(COLOR_SUCCESS);
    for(int i = 0; i < filled; i++) {
        printf("■");
    }
    setColor(COLOR_DEFAULT);
    for(int i = filled; i < BAR_LENGTH; i++) {
        printf("□");
    }
    printf(" (%d%%)\n", (current * 100) / max);
}

// ========== 플레이어 입력 ==========
int getPlayerInput(int usedNumbers[], int usedCount) {
    int input;
    int valid;
    
    do {
        valid = 1;
        setColor(COLOR_PLAYER);
        printf("\n  🎮 플레이어 차례!\n");
        setColor(COLOR_DEFAULT);
        printf("  선택 (1~10): ");
        scanf("%d", &input);
        
        // 범위 체크
        if(input < MIN_INPUT || input > MAX_INPUT) {
            setColor(COLOR_WARNING);
            printf("  ❌ 1에서 10 사이의 숫자만 입력 가능합니다!\n");
            setColor(COLOR_DEFAULT);
            playSound(300, 200);
            valid = 0;
            continue;
        }
        
        // 중복 체크
        for(int i = 0; i < usedCount; i++) {
            if(usedNumbers[i] == input) {
                setColor(COLOR_WARNING);
                printf("  ❌ 이미 사용한 숫자입니다!\n");
                setColor(COLOR_DEFAULT);
                playSound(300, 200);
                valid = 0;
                break;
            }
        }
    } while(!valid);
    
    playSound(600, 100);
    return input;
}

// ========== 컴퓨터 입력 (AI) ==========
int getComputerInput(int usedNumbers[], int usedCount, int lastPlayerInput, int difficulty) {
    int input;
    int valid;
    
    printf("\n  🤖 컴퓨터 생각 중");
    for(int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        Sleep(300);
    }
    printf("\n");
    
    // Hard Mode: 전략적 선택
    if(difficulty == 2 && lastPlayerInput > 0) {
        input = 11 - lastPlayerInput;
        
        // 이미 사용된 숫자면 랜덤으로
        for(int i = 0; i < usedCount; i++) {
            if(usedNumbers[i] == input) {
                input = -1;
                break;
            }
        }
    }
    
    // Easy Mode 또는 전략 실패 시: 랜덤 선택
    if(difficulty == 1 || input == -1) {
        do {
            valid = 1;
            input = (rand() % MAX_INPUT) + 1;
            
            for(int i = 0; i < usedCount; i++) {
                if(usedNumbers[i] == input) {
                    valid = 0;
                    break;
                }
            }
        } while(!valid);
    }
    
    setColor(COLOR_COMPUTER);
    printf("  🤖 컴퓨터가 %d를 선택했습니다!\n", input);
    setColor(COLOR_DEFAULT);
    
    playSound(500, 150);
    Sleep(500);
    
    return input;
}

// ========== 승자 표시 ==========
void showWinner(int isPlayer) {
    clearScreen();
    
    if(isPlayer) {
        setColor(COLOR_SUCCESS);
        printf("\n");
        printf("  ╔═══════════════════════════════╗\n");
        printf("  ║   🎉 축하합니다! 승리! 🎉    ║\n");
        printf("  ╚═══════════════════════════════╝\n\n");
        setColor(COLOR_DEFAULT);
        
        // 승리 사운드
        playSound(523, 150);
        playSound(659, 150);
        playSound(784, 150);
        playSound(1047, 300);
    } else {
        setColor(COLOR_WARNING);
        printf("\n");
        printf("  ╔═══════════════════════════════╗\n");
        printf("  ║      😢 아쉽게 패배...       ║\n");
        printf("  ╚═══════════════════════════════╝\n\n");
        setColor(COLOR_DEFAULT);
        
        // 패배 사운드
        playSound(392, 200);
        playSound(330, 200);
        playSound(262, 400);
    }
    
    printf("\n  Press any key to continue...");
    _getch();
}

// ========== 기록 저장 ==========
void saveRecord(int isPlayer) {
    FILE *fp = fopen("record.txt", "a");
    if(fp != NULL) {
        time_t now = time(NULL);
        fprintf(fp, "%s - %s\n", ctime(&now), isPlayer ? "플레이어 승리" : "컴퓨터 승리");
        fclose(fp);
    }
}

// ========== 게임 루프 ==========
void gameLoop(int difficulty) {
    int total = 0;
    int usedNumbers[MAX_INPUT];
    int usedCount = 0;
    int input;
    int isPlayerTurn = 1;
    int lastPlayerInput = 0;
    
    clearScreen();
    setColor(COLOR_TITLE);
    printf("\n  ═══════════════════════════════\n");
    printf("       🎮 게임 시작! 🎮\n");
    printf("  ═══════════════════════════════\n\n");
    setColor(COLOR_DEFAULT);
    
    playSound(700, 100);
    Sleep(1000);
    
    // 게임 진행
    while(total < TARGET_SCORE) {
        clearScreen();
        printf("\n  ═══════════════════════════════\n");
        printf("       🎯 100을 넘어라 게임 🎯\n");
        printf("  ═══════════════════════════════\n\n");
        
        drawProgressBar(total, TARGET_SCORE);
        printf("\n  사용된 숫자: ");
        for(int i = 0; i < usedCount; i++) {
            printf("%d ", usedNumbers[i]);
        }
        printf("\n");
        
        if(isPlayerTurn) {
            input = getPlayerInput(usedNumbers, usedCount);
            lastPlayerInput = input;
        } else {
            input = getComputerInput(usedNumbers, usedCount, lastPlayerInput, difficulty);
        }
        
        usedNumbers[usedCount++] = input;
        total += input;
        
        printf("\n  ➕ %d 추가 → 현재 합계: %d\n", input, total);
        Sleep(1000);
        
        if(total >= TARGET_SCORE) {
            showWinner(isPlayerTurn);
            saveRecord(isPlayerTurn);
            break;
        }
        
        isPlayerTurn = !isPlayerTurn;
    }
}

// ========== 데모 모드 ==========
void demoMode() {
    printf("\n  🎬 데모 모드 실행 중...\n\n");
    
    int total = 0;
    int turn = 1;
    
    while(total < TARGET_SCORE && turn < 6) {
        int num = (rand() % 10) + 1;
        total += num;
        printf("  턴 %d: %d 선택 → 합계: %d\n", turn, num, total);
        playSound(500 + (turn * 50), 100);
        Sleep(1000);
        turn++;
    }
    
    printf("\n  데모 종료!\n");
}

// ========== 메인 함수 ==========
int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    // 데모 모드 체크
    if(argc > 1 && strcmp(argv[1], "--demo") == 0) {
        demoMode();
        return 0;
    }
    
    // 인트로 화면
    intro();
    
    // 메인 루프
    char replay;
    do {
        int choice = showMenu();
        
        switch(choice) {
            case 1:
                gameLoop(1);  // Easy Mode
                break;
            case 2:
                gameLoop(2);  // Hard Mode
                break;
            case 3:
                showRules();
                continue;
            case 4:
                clearScreen();
                setColor(COLOR_TITLE);
                printf("\n  👋 게임을 종료합니다. 감사합니다!\n\n");
                setColor(COLOR_DEFAULT);
                playSound(523, 200);
                return 0;
            default:
                setColor(COLOR_WARNING);
                printf("\n  ❌ 잘못된 선택입니다!\n");
                setColor(COLOR_DEFAULT);
                Sleep(1000);
                continue;
        }
        
        // 재시작 여부
        clearScreen();
        printf("\n  🔄 다시 플레이하시겠습니까? (Y/N): ");
        scanf(" %c", &replay);
        
    } while(replay == 'Y' || replay == 'y');
    
    clearScreen();
    setColor(COLOR_TITLE);
    printf("\n  ═══════════════════════════════\n");
    printf("       👋 감사합니다! 👋\n");
    printf("  ═══════════════════════════════\n\n");
    setColor(COLOR_DEFAULT);
    
    playSound(523, 150);
    playSound(392, 150);
    playSound(330, 200);
    
    return 0;
}