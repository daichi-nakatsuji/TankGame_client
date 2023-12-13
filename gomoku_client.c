//http://blog.livedoor.jp/akf0/archives/51585502.html
//-lws2_32

#include <stdio.h>
#include <winsock2.h>

#define SIZE 15

// �Ղ̏�����(�ǉ������A�폜�s��)
void initializeBoard(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;		//�󂢂Ă���ꏊ��0�ɐݒ�
        }
    }
}

//�R���є���(�ǉ������A�폜�s��)
int checkThreeBrock(int board[SIZE][SIZE], int FstPlayer, int SecPlayer, int row, int col, int gradient){
    switch(gradient){
        case 0:     //��
            if((col-4 < 0 && col+2 >= SIZE && board[row][col-4] == SecPlayer && board[row][col-3] == 0 && board[row][col-2] == FstPlayer && board[row][col-1] == FstPlayer && board[row][col+1] == 0 && board[row][col+2] == SecPlayer) ||
               (col-3 < 0 && col+3 >= SIZE && board[row][col-3] == SecPlayer && board[row][col-2] == 0 && board[row][col-1] == FstPlayer && board[row][col+1] == FstPlayer && board[row][col+2] == 0 && board[row][col+3] == SecPlayer) ||
               (col-2 < 0 && col+4 >= SIZE && board[row][col-2] == SecPlayer && board[row][col-1] == 0 && board[row][col+1] == FstPlayer && board[row][col+2] == FstPlayer && board[row][col+3] == 0 && board[row][col+4] == SecPlayer)){
                return 0;
            }
            if((col-4 < 0 && col+1 >= SIZE && board[row][col-4] == 0 && board[row][col-3] == FstPlayer && board[row][col-2] == FstPlayer && board[row][col-1] == 0 && board[row][col+1] == 0) ||
               (col-4 < 0 && col+1 >= SIZE && board[row][col-4] == 0 && board[row][col-3] == FstPlayer && board[row][col-2] == 0 && board[row][col-1] == FstPlayer && board[row][col+1] == 0) || 
               (col-4 < 0 && col+2 >= SIZE && board[row][col-4] == 0 && board[row][col-3] == 0 && board[row][col-2] == FstPlayer && board[row][col-1] == FstPlayer && board[row][col+1] == 0 && board[row][col+2] == 0) ||
               (col-3 < 0 && col+2 >= SIZE && board[row][col-3] == 0 && board[row][col-2] == FstPlayer && board[row][col-1] == 0 && board[row][col+1] == FstPlayer && board[row][col+2] == 0) ||
               (col-2 < 0 && col+3 >= SIZE && board[row][col-2] == 0 && board[row][col-1] == FstPlayer && board[row][col+1] == 0 && board[row][col+2] == FstPlayer && board[row][col+3] == 0) ||
               (col-3 < 0 && col+3 >= SIZE && board[row][col-3] == 0 && board[row][col-2] == 0 && board[row][col-1] == FstPlayer && board[row][col+1] == FstPlayer && board[row][col+2] == 0 && board[row][col+3] == 0) ||
               (col-1 < 0 && col+4 >= SIZE && board[row][col-1] == 0 && board[row][col+1] == FstPlayer && board[row][col+2] == 0 && board[row][col+3] == FstPlayer && board[row][col+4] == 0) ||
               (col-1 < 0 && col+4 >= SIZE && board[row][col-1] == 0 && board[row][col+1] == 0 && board[row][col+2] == FstPlayer && board[row][col+3] == FstPlayer && board[row][col+4] == 0) ||
               (col-2 < 0 && col+4 >= SIZE && board[row][col-2] == 0 && board[row][col-1] == 0 && board[row][col+1] == FstPlayer && board[row][col+2] == FstPlayer && board[row][col+3] == 0 && board[row][col+4] == 0)) {
                return 1;
            }
            break;
        case 1:     //�c
            if((row-4 < 0 && row+2 >= SIZE && board[row-4][col] == SecPlayer && board[row-3][col] == 0 && board[row-2][col] == FstPlayer && board[row-1][col] == FstPlayer && board[row+1][col] == 0 && board[row+2][col] == SecPlayer) ||
               (row-3 < 0 && row+3 >= SIZE && board[row-3][col] == SecPlayer && board[row-2][col] == 0 && board[row-1][col] == FstPlayer && board[row+1][col] == FstPlayer && board[row+2][col] == 0 && board[row+3][col] == SecPlayer) ||
               (row-2 < 0 && row+4 >= SIZE && board[row-2][col] == SecPlayer && board[row-1][col] == 0 && board[row+1][col] == FstPlayer && board[row+2][col] == FstPlayer && board[row+3][col] == 0 && board[row+4][col] == SecPlayer)){
                return 0;
            }
            if((row-4 < 0 && row+1 >= SIZE && board[row-4][col] == 0 && board[row-3][col] == FstPlayer && board[row-2][col] == FstPlayer && board[row-1][col] == 0 && board[row+1][col] == 0) ||
               (row-4 < 0 && row+1 >= SIZE && board[row-4][col] == 0 && board[row-3][col] == FstPlayer && board[row-2][col] == 0 && board[row-1][col] == FstPlayer && board[row+1][col] == 0) || 
               (row-4 < 0 && row+2 >= SIZE && board[row-4][col] == 0 && board[row-3][col] == 0 && board[row-2][col] == FstPlayer && board[row-1][col] == FstPlayer && board[row+1][col] == 0 && board[row+2][col] == 0) ||
               (row-3 < 0 && row+2 >= SIZE && board[row-3][col] == 0 && board[row-2][col] == FstPlayer && board[row-1][col] == 0 && board[row+1][col] == FstPlayer && board[row+2][col] == 0) ||
               (row-2 < 0 && row+3 >= SIZE && board[row-2][col] == 0 && board[row-1][col] == FstPlayer && board[row+1][col] == 0 && board[row+2][col] == FstPlayer && board[row+3][col] == 0) ||
               (row-3 < 0 && row+3 >= SIZE && board[row-3][col] == 0 && board[row-2][col] == 0 && board[row-1][col] == FstPlayer && board[row+1][col] == FstPlayer && board[row+2][col] == 0 && board[row+3][col] == 0) ||
               (row-1 < 0 && row+4 >= SIZE && board[row-1][col] == 0 && board[row+1][col] == FstPlayer && board[row+2][col] == 0 && board[row+3][col] == FstPlayer && board[row+4][col] == 0) ||
               (row-1 < 0 && row+4 >= SIZE && board[row-1][col] == 0 && board[row+1][col] == 0 && board[row+2][col] == FstPlayer && board[row+3][col] == FstPlayer && board[row+4][col] == 0) ||
               (row-2 < 0 && row+4 >= SIZE && board[row-2][col] == 0 && board[row-1][col] == 0 && board[row+1][col] == FstPlayer && board[row+2][col] == FstPlayer && board[row+3][col] == 0 && board[row+4][col] == 0)) {
                return 1;
            }
            break;
        case 2:     //���ォ��E��
            if((col-4 < 0 && col+2 >= SIZE && row-4 < 0 && row+2 >= SIZE && board[row-4][col-4] == SecPlayer && board[row-3][col-3] == 0 && board[row-2][col-2] == FstPlayer && board[row-1][col-1] == FstPlayer && board[row+1][col+1] == 0 && board[row+2][col+2] == SecPlayer) ||
               (col-3 < 0 && col+3 >= SIZE && row-3 < 0 && row+3 >= SIZE && board[row-3][col-3] == SecPlayer && board[row-2][col-2] == 0 && board[row-1][col-1] == FstPlayer && board[row+1][col+1] == FstPlayer && board[row+2][col+2] == 0 && board[row+3][col+3] == SecPlayer) ||
               (col-2 < 0 && col+4 >= SIZE && row-2 < 0 && row+4 >= SIZE && board[row-2][col-2] == SecPlayer && board[row-1][col-1] == 0 && board[row+1][col+1] == FstPlayer && board[row+2][col+2] == FstPlayer && board[row+3][col+3] == 0 && board[row+4][col+4] == SecPlayer)){
                return 0;
            }
            if((col-4 < 0 && col+1 >= SIZE && row-4 < 0 && row+1 >= SIZE && board[row-4][col-4] == 0 && board[row-3][col-3] == FstPlayer && board[row-2][col-2] == FstPlayer && board[row-1][col-1] == 0 && board[row+1][col+1] == 0) ||
               (col-4 < 0 && col+1 >= SIZE && row-4 < 0 && row+1 >= SIZE && board[row-4][col-4] == 0 && board[row-3][col-3] == FstPlayer && board[row-2][col-2] == 0 && board[row-1][col-1] == FstPlayer && board[row+1][col+1] == 0) || 
               (col-4 < 0 && col+2 >= SIZE && row-4 < 0 && row+2 >= SIZE && board[row-4][col-4] == 0 && board[row-3][col-3] == 0 && board[row-2][col-2] == FstPlayer && board[row-1][col-1] == FstPlayer && board[row+1][col+1] == 0 && board[row+2][col+2] == 0) ||
               (col-3 < 0 && col+2 >= SIZE && row-3 < 0 && row+2 >= SIZE && board[row-3][col-3] == 0 && board[row-2][col-2] == FstPlayer && board[row-1][col-1] == 0 && board[row+1][col+1] == FstPlayer && board[row+2][col+2] == 0) ||
               (col-2 < 0 && col+3 >= SIZE && row-2 < 0 && row+3 >= SIZE && board[row-2][col-2] == 0 && board[row-1][col-1] == FstPlayer && board[row+1][col+1] == 0 && board[row+2][col+2] == FstPlayer && board[row+3][col+3] == 0) ||
               (col-3 < 0 && col+3 >= SIZE && row-3 < 0 && row+3 >= SIZE && board[row-3][col-3] == 0 && board[row-2][col-2] == 0 && board[row-1][col-1] == FstPlayer && board[row+1][col+1] == FstPlayer && board[row+2][col+2] == 0 && board[row+3][col+3] == 0) ||
               (col-1 < 0 && col+4 >= SIZE && row-1 < 0 && row+4 >= SIZE && board[row-1][col-1] == 0 && board[row+1][col+1] == FstPlayer && board[row+2][col+2] == 0 && board[row+3][col+3] == FstPlayer && board[row+4][col+4] == 0) ||
               (col-1 < 0 && col+4 >= SIZE && row-1 < 0 && row+4 >= SIZE && board[row-1][col-1] == 0 && board[row+1][col+1] == 0 && board[row+2][col+2] == FstPlayer && board[row+3][col+3] == FstPlayer && board[row+4][col+4] == 0) ||
               (col-2 < 0 && col+4 >= SIZE && row-2 < 0 && row+4 >= SIZE && board[row-2][col-2] == 0 && board[row-1][col-1] == 0 && board[row+1][col+1] == FstPlayer && board[row+2][col+2] == FstPlayer && board[row+3][col+3] == 0 && board[row+4][col+4] == 0)) {
                return 1;
            }
            break;
        case 3:     //�E�ォ�獶��
            if((col-4 < 0 && col+2 >= SIZE && row+4 < 0 && row-2 >= SIZE && board[row+4][col-4] == SecPlayer && board[row+3][col-3] == 0 && board[row+2][col-2] == FstPlayer && board[row+1][col-1] == FstPlayer && board[row-1][col+1] == 0 && board[row-2][col+2] == SecPlayer) ||
               (col-3 < 0 && col+3 >= SIZE && row+3 < 0 && row-3 >= SIZE && board[row+3][col-3] == SecPlayer && board[row+2][col-2] == 0 && board[row+1][col-1] == FstPlayer && board[row-1][col+1] == FstPlayer && board[row-2][col+2] == 0 && board[row-3][col+3] == SecPlayer) ||
               (col-2 < 0 && col+4 >= SIZE && row+2 < 0 && row-4 >= SIZE && board[row+2][col-2] == SecPlayer && board[row+1][col-1] == 0 && board[row-1][col+1] == FstPlayer && board[row-2][col+2] == FstPlayer && board[row-3][col+3] == 0 && board[row-4][col+4] == SecPlayer)){
                return 0;
            }
            if((col-4 < 0 && col+1 >= SIZE && row+4 < 0 && row-1 >= SIZE && board[row+4][col-4] == 0 && board[row+3][col-3] == FstPlayer && board[row+2][col-2] == FstPlayer && board[row+1][col-1] == 0 && board[row-1][col+1] == 0) ||
               (col-4 < 0 && col+1 >= SIZE && row+4 < 0 && row-1 >= SIZE && board[row+4][col-4] == 0 && board[row+3][col-3] == FstPlayer && board[row+2][col-2] == 0 && board[row+1][col-1] == FstPlayer && board[row-1][col+1] == 0) || 
               (col-4 < 0 && col+2 >= SIZE && row+4 < 0 && row-2 >= SIZE && board[row+4][col-4] == 0 && board[row+3][col-3] == 0 && board[row+2][col-2] == FstPlayer && board[row+1][col-1] == FstPlayer && board[row-1][col+1] == 0 && board[row-2][col+2] == 0) ||
               (col-3 < 0 && col+2 >= SIZE && row+3 < 0 && row-2 >= SIZE && board[row+3][col-3] == 0 && board[row+2][col-2] == FstPlayer && board[row+1][col-1] == 0 && board[row-1][col+1] == FstPlayer && board[row-2][col+2] == 0) ||
               (col-2 < 0 && col+3 >= SIZE && row+2 < 0 && row-3 >= SIZE && board[row+2][col-2] == 0 && board[row+1][col-1] == FstPlayer && board[row-1][col+1] == 0 && board[row-2][col+2] == FstPlayer && board[row-3][col+3] == 0) ||
               (col-3 < 0 && col+3 >= SIZE && row+3 < 0 && row-3 >= SIZE && board[row+3][col-3] == 0 && board[row+2][col-2] == 0 && board[row+1][col-1] == FstPlayer && board[row-1][col+1] == FstPlayer && board[row-2][col+2] == 0 && board[row-3][col+3] == 0) ||
               (col-1 < 0 && col+4 >= SIZE && row+1 < 0 && row-4 >= SIZE && board[row+1][col-1] == 0 && board[row-1][col+1] == FstPlayer && board[row-2][col+2] == 0 && board[row-3][col+3] == FstPlayer && board[row-4][col+4] == 0) ||
               (col-1 < 0 && col+4 >= SIZE && row+1 < 0 && row-4 >= SIZE && board[row+1][col-1] == 0 && board[row-1][col+1] == 0 && board[row-2][col+2] == FstPlayer && board[row-3][col+3] == FstPlayer && board[row-4][col+4] == 0) ||
               (col-2 < 0 && col+4 >= SIZE && row+2 < 0 && row-4 >= SIZE && board[row+2][col-2] == 0 && board[row+1][col-1] == 0 && board[row-1][col+1] == FstPlayer && board[row-2][col+2] == FstPlayer && board[row-3][col+3] == 0 && board[row-4][col+4] == 0)) {
                return 1;
            }
            break;
        default:
            break;
    }

    return 0;
}

//4���є���(�ǉ������A�폜�s��)
int checkFourBrock(int board[SIZE][SIZE], int FstPlayer, int SecPlayer, int row, int col, int gradient){

}

//�ւ��蔻��(�ǉ������A�폜�s��)
int checkForbiddenMoves(int board[SIZE][SIZE], int FstPlayer, int SecPlayer, int row, int col){
	int consecutiveCount = 0;
	//�O�O��
    for(int i = 0; i < 4; i++){
        if(checkThreeBrock(board,FstPlayer, SecPlayer, row, col, i)){
            consecutiveCount++;
        }
    }
    if(consecutiveCount >=2) return 1; //�ւ���

	//�l�l��
    consecutiveCount = 0;

	//���A
	// ������
    consecutiveCount = 0;
    for (int i = col - 5; i <= col + 5; i++) {
        if (i < 0 || i >= SIZE) continue;
        if (board[row][i] == FstPlayer) {
            consecutiveCount++;
            if (consecutiveCount == 6) return 1; //�ւ���
        } else {
            consecutiveCount = 0;
        }
    }

    // �c����
    consecutiveCount = 0;
    for (int i = row - 5; i <= row + 5; i++) {
        if (i < 0 || i >= SIZE) continue;
        if (board[i][col] == FstPlayer) {
            consecutiveCount++;
            if (consecutiveCount == 6) return 1; //�ւ���
        } else {
            consecutiveCount = 0;
        }
    }

    // �΂ߕ��� (���ォ��E��)
    consecutiveCount = 0;
    for (int i = -5; i <= 5; i++) {
        int r = row + i;
        int c = col + i;
        if (r < 0 || r >= SIZE || c < 0 || c >= SIZE) continue;
        if (board[r][c] == FstPlayer) {
            consecutiveCount++;
            if (consecutiveCount == 6) return 1; //�ւ���
        } else {
            consecutiveCount = 0;
        }
    }

    // �΂ߕ��� (�E�ォ�獶��)
    consecutiveCount = 0;
    for (int i = -5; i <= 5; i++) {
        int r = row + i;
        int c = col - i;
        if (r < 0 || r >= SIZE || c < 0 || c >= SIZE) continue;
        if (board[r][c] == FstPlayer) {
            consecutiveCount++;
            if (consecutiveCount == 6) return 1; //�ւ���
        } else {
            consecutiveCount = 0;
        }
    }

	return 0;	//�ւ���Ȃ�
}

// ������������(�ǉ������A�폜�s��)
int checkDraw(int board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return 0; // �{�[�h���܂����܂��Ă��Ȃ�
            }
        }
    }
    return 1; // �{�[�h�����܂��Ă���
}

//��������(�ǉ������A�폜�s��)
int checkWin(int board[SIZE][SIZE], int player, int row, int col) {
    int consecutiveCount = 0;

    // ������
    for (int i = col - 4; i <= col + 4; i++) {
        if (i < 0 || i >= SIZE) continue;
        if (board[row][i] == player) {
            consecutiveCount++;
            if (consecutiveCount == 5) return 1; // ����
        } else {
            consecutiveCount = 0;
        }
    }

    // �c����
    consecutiveCount = 0;
    for (int i = row - 4; i <= row + 4; i++) {
        if (i < 0 || i >= SIZE) continue;
        if (board[i][col] == player) {
            consecutiveCount++;
            if (consecutiveCount == 5) return 1; // ����
        } else {
            consecutiveCount = 0;
        }
    }

    // �΂ߕ��� (���ォ��E��)
    consecutiveCount = 0;
    for (int i = -4; i <= 4; i++) {
        int r = row + i;
        int c = col + i;
        if (r < 0 || r >= SIZE || c < 0 || c >= SIZE) continue;
        if (board[r][c] == player) {
            consecutiveCount++;
            if (consecutiveCount == 5) return 1; // ����
        } else {
            consecutiveCount = 0;
        }
    }

    // �΂ߕ��� (�E�ォ�獶��)
    consecutiveCount = 0;
    for (int i = -4; i <= 4; i++) {
        int r = row + i;
        int c = col - i;
        if (r < 0 || r >= SIZE || c < 0 || c >= SIZE) continue;
        if (board[r][c] == player) {
            consecutiveCount++;
            if (consecutiveCount == 5) return 1; // ����
        } else {
            consecutiveCount = 0;
        }
    }

    return 0; // �����Ȃ�
}

int main(void) {	

	//�ڑ�����T�[�o�̏��̍\���̂�p��

	struct sockaddr_in dest;

	memset(&dest, 0, sizeof(dest));

	//�T�[�o�̏������

	char destination[100];  //�A�h���X
	int port;		//�|�[�g�ԍ�

	printf("�A�h���X����͂��Ă�������");
	scanf("%s", destination);
	printf("�|�[�g�ԍ�����͂��Ă�������");
	scanf("%d", &port);
	dest.sin_port = htons(port);
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = inet_addr(destination);



	//�\�P�b�g�ʐM�̏����E����
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

	//�T�[�o�ւ̐ڑ�
	if (connect(s, (struct sockaddr *) &dest, sizeof(dest))) {
		printf("%s�ɐڑ��ł��܂���ł���\n", destination);
		return -1;

	}

	printf("%s�ɐڑ����܂���\n", destination);
	
	char msg[1024];
	char buffer[1024];
	int board[SIZE][SIZE];	//�Ղ̍쐬
	initializeBoard(board);	//�Ղ̏�����

	boolean isFirst = TRUE;	//���O���͂��ǂ����̔���
	int Advance;		//��U���ǂ���
	int row, col;			//�ł�����̈ʒu
	int your = 1;			//�����̎��1�ɐݒ�
	int com = 2;			//����̎���Q�ɐݒ�

	//��U����U��(�ǉ������A�폜�s��)
	if(port == 12345){
		Advance = your;		//���g����U
	}else{
		Advance = com;	//���g����U
	}

	//�T�[�o����f�[�^����M
	recv(s, buffer, 1024, 0);
	printf("�� %s\n\n", buffer);

	while(1){
		char buffer2[1024];
		memset(buffer2, 0, sizeof(buffer2));
		
		if(isFirst){
			//���O�̓���
			printf("���M���b�Z�[�W�����(q�ŏI��)");
			scanf("%s", msg);
			if(msg[0] == 'q' || msg[0] == 'Q'){
				break;
			}
            isFirst = FALSE;
		}else{
			// ����̎����(�ǉ������A�폜�s��)
			if(strcmp(buffer2, "start") != 0){
                sscanf(buffer2, "%d,%d", &row, &col);
				row--;
				col--;
				board[row][col] = com;
			}
			
			// �ւ���̔��f(�ǉ������A�폜�s��)
			if(Advance == com && checkForbiddenMoves(board, com, your, row, col) == 1){
				const char Forbidden[1024] = "Yuor hands is Forbidden";
				send(s, Forbidden, strlen(Forbidden), 0);
				break;
			}

			// �����������f(�ǉ������A�폜�s��)
			if (checkDraw(board)) {
				const char drow[1024] = "The game is a draw!";
				send(s, drow, strlen(drow), 0);
				break;
			}

			//�����̎������(����ύX)
			printf("���M���b�Z�[�W�����(q�ŏI��)");
			scanf("%s", msg);
			if(msg[0] == 'q' || msg[0] == 'Q'){
				break;
			}

			//�������f(����ǉ�)
			

		}
		//�T�[�o�Ƀf�[�^�𑗐M
		send(s, msg, strlen(msg), 0);

		//�T�[�o����f�[�^����M
		recv(s, buffer2, 1024, 0);
		printf("�� %s\n\n", buffer2);
	}

	// Windows �ł̃\�P�b�g�̏I��
	closesocket(s);
	WSACleanup();
	return 0;

}