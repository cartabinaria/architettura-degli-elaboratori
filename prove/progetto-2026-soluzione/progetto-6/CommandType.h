#ifndef COMMAND_TYPE_H
#define COMMAND_TYPE_H

typedef enum 
{
  C_NULL,
  C_ARITHMETIC,
  C_PUSH,
  C_POP,
  C_LABEL,
  C_GOTO,
  C_IF,
  C_FUNCTION,
  C_RETURN,
  C_CALL
} CommandType;

#endif