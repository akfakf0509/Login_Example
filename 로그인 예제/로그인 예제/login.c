#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int account_num = 0;
char **id, **password;

int login() {
	char input_id[20] = "", input_password[20] = "";
	int is_passed = 0;
	printf("아이디 :");
	scanf("%s", &input_id);
	printf("비밀번호 :");
	scanf("%s", &input_password);
	for (int a = 0; a < account_num; a++) {
		if (strcmp(id[a], input_id) == 0 && strcmp(password[a], input_password) == 0)
			is_passed = 1;
	}
	if (is_passed)
		printf("로그인 성공!\n");
	else
		printf("일치하지 않습니다.\n");
	return 0;
}
int new_account(int new_kind) {
	char input_id[20] = "", input_password[20] = "";
	if (new_kind == 1 || new_kind == 0) {
		while (1) {
			printf("새로운 아이디 :");
			scanf("%s", &input_id);
			for (int a = 0; a < account_num; a++) {
				if (strcmp(input_id, id[a]) == 0) {
					printf("이미존재하는 아이디입니다.\n");
					new_account(0);
					return 0;
				}
			}
			break;
		}
	}
	if (new_kind == 2 || new_kind == 0) {
		while (1) {
			printf("비밀번호 :");
			scanf("%s", &input_password);
			char re_input_password[20] = "";
			printf("비밀번호 확인 :");
			scanf("%s", &re_input_password);
			if (strcmp(input_password, re_input_password) == 0 && account_num != 0) {
				for (int a = 0; a < account_num; a++) {
					account_num += 1;
					char **tmp_id = id, **tmp_password = password;

					id = (char**)malloc(sizeof(char*)*account_num);
					password = (char**)malloc(sizeof(char*)*account_num);

					for (int b = 0; b < account_num; b++) {
						id[b] = (char*)malloc(sizeof(char) * 20);
						password[b] = (char*)malloc(sizeof(char) * 20);
					}
					for (int b = 0; b < account_num - 1; b++) {
						for (int c = 0; c < 20; c++) {
							id[b][c] = tmp_id[b][c];
							password[b][c] = tmp_password[b][c];
						}
					}
					for (int b = 0; b < 20; b++) {
						id[account_num - 1][b] = input_id[b];
						password[account_num - 1][b] = input_password[b];
					}
					for (int b = 0; b < account_num - 1; b++) {
						free(tmp_id[b]);
						free(tmp_password[b]);
					}
					free(tmp_id);
					free(tmp_password);
					printf("완료 \n");
					return 0;
				}
			}
			else if (strcmp(input_password, re_input_password) == 0 && account_num == 0) {
				account_num += 1;
				char **tmp_id = id, **tmp_password = password;

				id = (char**)malloc(sizeof(char*)*account_num);
				password = (char**)malloc(sizeof(char*)*account_num);

				for (int b = 0; b < account_num; b++) {
					id[b] = (char*)malloc(sizeof(char) * 20);
					password[b] = (char*)malloc(sizeof(char) * 20);
				}
				for (int b = 0; b < 20; b++) {
					id[account_num - 1][b] = input_id[b];
					password[account_num - 1][b] = input_password[b];
				}
				for (int b = 0; b < account_num - 1; b++) {
					free(tmp_id[b]);
					free(tmp_password[b]);
				}
				free(tmp_id);
				free(tmp_password);
				printf("완료 \n");
				return 0;
			}
			else {
				printf("비밀번호가 일치하지않습니다.\n");
				new_account(2);
				break;
			}
		}
	}
	return 0;
}

int list_id() {
	printf("등록되어 있는 모든 아이디를 출력합니다.\n");
	printf("---------------------------------\n");
	for (int a = 0; a < account_num; a++)
		printf("%d | %s\n", a, id[a]);
	printf("---------------------------------\n");
	return 0;
}

int find_password() {
	char input_id[20] = "";
	while (1) {
		printf("비밀번호를 찾을 아이디를 입력해주세요.\n");
		scanf("%s", &input_id);
		for (int a = 0; a < account_num; a++) {
			if (strcmp(input_id, id[a]) == 0) {
				printf("---------------------------------\n");
				printf("검색한 ID : %s | PASSWORD : %s\n", input_id, password[a]);
				printf("---------------------------------\n");
				return 0;
			}
		}
		printf("해당 아이디가 존재하지 않습니다.\n");
		return 0;
	}
	return 0;
}

int main() {
	int todo = 0;
	while (1) {
		printf("작업을 선택하세요.\n");
		printf("1.로그인 2.아이디 찾기 3.비밀번호 찾기 4.회원가입 5.종료\n");
		while (1) {
			todo = 0;
			scanf("%d", &todo);
			getchar();
			if (todo > 5 || todo < 1) {
				printf("없는 작업입니다.\n");
			}
			else
				break;
		}
		switch (todo)
		{
		case 1:
			login();
			break;
		case 2:
			list_id();
			break;
		case 3:
			find_password();
			break;
		case 4:
			new_account(0);
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
}