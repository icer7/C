/* ソケットファイル記述子、および送信対象のnullで終端された
 * 文字列へのポインタを受け取る。文字列の全バイトの送信を保証
 * する。成功時は1を返し、失敗時は0を返す。
 */

int send_string(int sockfd, unsigned char *buffer) {
	int sent_bytes, bytes_to_send;
	bytes_to_send = strlen(buffer);
	while(bytes_to_send > 0) {
		sent_bytes = send(sockfd, buffer, bytes_to_send, 0);
		if(sent_bytes == -1)
			return 0;
		bytes_to_send -= sent_bytes;
		buffer += sent_bytes;
	}
	return 1;
}

/* ソケットファイル記述子と出力バッファへのポインタを
 * 受け取る。これはEOLバイト群に遭遇するまでソケットからデータを
 * 受信する。EOLバイトはソケットから読み込まれるものの、出力
 * バッファはEOLバイト群の直前で終端される。
 * 読み込んだ行のサイズ（EOLバイトを省く）を返す。
 */

int recv_line(int sockfd, unsigned char *dest_buffer) {
#define EOL "\r\n"
#define EOL_SIZE00 2
	unsigned char *ptr;
	int eol_matched = 0;

	ptr = dest_buffer;
	while(recv(sockfd, ptr, 1, 0) == 1) {
		if(*ptr == EOL[eol_matched]) {
			eol_matched++;
			if(eol_matched == EOL_SIZE) {
				*(ptr+1-EOL_SIZE) = '\0';
				return strlen(dest_buffer);
			}
		} else {
			eol_matched = 0;
		}
		ptr++;
	}
	return 0;
}
