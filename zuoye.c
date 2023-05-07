#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 删除行末空白字符
void Cut(FILE *src, FILE *dst);

int main()
{
    char sname[1024], dname[1024];
    FILE *sfile, *dfile;

    gets(sname);
    gets(dname);

    sfile = fopen(sname, "rb");
    if (!sfile)
    {
        printf("%s 无法打开!\n", sfile);
    }
    dfile = fopen(dname, "wb");
    if (!dfile)
    {
        printf("%s 无法打开!\n", dfile);
    }

    if (sfile && dfile)
    {
        printf("正在整理...");
        Cut(sfile, dfile);
        puts("整理完成!");
    }

    if (sfile)
    {
        fclose(sfile);
    }
    if (dfile)
    {
        fclose(dfile);
    }
    return 0;
}

/* 你提交的代码将被嵌在这里 */


void Cut(FILE *src, FILE *dst)
{
    char buf[1024];
    char *ptr;

    while (fgets(buf, sizeof(buf), src)) 
    {
        ptr = buf + strlen(buf) - 1;
        while (ptr >= buf && isspace(*ptr))
        {
            *ptr-- = '\0';
        }
        fprintf(dst, "%s\n", buf);
    }
}
