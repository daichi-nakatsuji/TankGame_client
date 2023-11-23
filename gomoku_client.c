//http://blog.livedoor.jp/akf0/archives/51585502.html

#include <stdio.h>
#include <winsock2.h>

#define SIZE 15

// �Ղ̏�����(�ǉ������A�폜�s��)
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '0';
        }
    }
}

// ������������(�ǉ������A�폜�s��)
int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // �{�[�h���܂����܂��Ă��Ȃ�
            }
        }
    }
    return 1; // �{�[�h�����܂��Ă���
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
	char board[SIZE][SIZE];
	initializeBoard(board);
	boolean isFirst = TRUE;
	int row, col;
	
	//�T�[�o����f�[�^����M
	recv(s, buffer, 1024, 0);
	printf("�� %s\n\n", buffer);

	while(1){
		char buffer2[1024];
		memset(buffer2, 0, sizeof(buffer2));
		
		// ����̎����(�ǉ������A�폜�s��)
		if(isFirst){
			sscanf(buffer, "%d,%d", &row, &col);
			isFirst = FALSE;
		}else{
			sscanf(buffer2, "%d,%d", &row, &col);
		}
		row--;
		col--;
		board[row][col] = '1';

		// �ւ���̔��f(�ǉ������A�폜�s��)

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