#ifndef __OBJMGT_H__
#define __OBJMGT_H__

int  AddObject (unsigned int key1, unsigned int key2, unsigned int key3);
void  DeleteObject (unsigned int key1, unsigned int key2, unsigned int key3);
int  IsObjectExist (unsigned int key1, unsigned int key2, unsigned int key3);
void Clear(void);
#endif
