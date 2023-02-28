#include <sys/stat.h>
#include <sys/time.h>
#include <utime.h>
#include <unistd.h>
#include <iostream>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
using namespace std;

bool MyFileCopy(char* src, char* obj) {
	int srchandle = open(src, 0);
	struct stat buf;
	stat(src, &buf);
	int objhandle = creat(obj, buf.st_mode);
	char content[2000];
	int size;
	for (; (size = read(srchandle, content, 2000)) > 0;)
	{
		if (write(objhandle, content,size) != size)
		{
			cout << "write incomplete!" << endl;
			return false;
		}
	}
	struct utimbuf time_set;
	time_set.actime = buf.st_atime;
	time_set.modtime = buf.st_mtime;
	utime(obj, &time_set);
	close(srchandle);
	close(objhandle);
	return true;
}

bool MyLinkCopy(char* src, char* obj) {
	char old_path[1000];
	char content[2000];
	struct stat buffer;
	memset(content, 0, sizeof(content));
	getcwd(old_path, sizeof(old_path));
	strcat(old_path, "/");
	readlink(src, content, 2000);
	symlink(strcat(old_path, src), obj);
	lstat(src, &buffer);
	struct timeval time_set[2];
	time_set[0].tv_sec = buffer.st_atime;
	time_set[0].tv_usec = 0;
	time_set[1].tv_sec = buffer.st_mtime;
	time_set[1].tv_usec = 0;
	lutimes(obj, time_set);
	return true;
}

bool MyCopy(char* src, char* obj) {
	cout<<"obj is :"<<obj<<endl;
	DIR* dir;
	struct stat buf;
	struct dirent* node;
	char source[1000], object[1000];
	strcpy(object, obj);
	strcat(object, "/");
	if ((dir = opendir(src)) == NULL) {
		cout << "MyCopy Opendir error!" << endl;
		return false;
	}
	for (; (node = readdir(dir)) != NULL;) 
	{//遍历所有文件
		if (node->d_type == 4)//若为目录
		{
			if (strcmp(node->d_name, ".") != 0 && strcmp(node->d_name, "..") != 0)
			{ //若既不是当前目录也不是父目录,则创建新目录
				memset(source, 0, sizeof(source));
				strcpy(source, src);
				strcat(source, "/");
				strcat(source, node->d_name);
				strcat(object, node->d_name);
				stat(source, &buf);
				mkdir(object, buf.st_mode);
				MyCopy(source, object);
				struct utimbuf time_set;
				time_set.actime = buf.st_atime;
				time_set.modtime = buf.st_mtime;
				utime(object, &time_set);
				strcpy(object, obj);
				strcat(object, "/");
			}
		}
		else if (node->d_type == 10) //若为软链接
		{
			memset(source, 0, sizeof(source));
			strcpy(source, src);
			strcat(source, "/");
			strcat(source, node->d_name);
			strcat(object, node->d_name);
			if (MyLinkCopy(source, object) == false)
				return false;
			strcpy(object, obj);
			strcat(object, "/");
		}
		else//若为文件
		{
			memset(source, 0, sizeof(source));
			strcpy(source, src);
			strcat(source, "/");
			strcat(source, node->d_name);
			strcat(object, node->d_name);
			if(MyFileCopy(source, object)==false)
				return false;
			strcpy(object, obj);
			strcat(object, "/");
		}
	}
	closedir(dir);
	return true;
}

int main(int argc,char* argv[])
{
	DIR* dir;
	struct stat buffer;
	if ((dir == opendir(argv[2])) == NULL) {
		stat(argv[1], &buffer);
		mkdir(argv[2], buffer.st_mode);
		cout << "mkdir succeed!" << endl;
	}
	if (MyCopy(argv[1], argv[2]) == false)
		return 0;
	struct utimbuf time_set;
	time_set.actime = buffer.st_atime;
	time_set.modtime = buffer.st_mtime;
	utime(argv[2], &time_set);
	cout << "copy file done" << endl;
	return 0;
}
