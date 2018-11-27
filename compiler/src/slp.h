#pragma once

typedef char *string;
typedef struct A_stm_ *A_stm;
typedef struct A_exp_ *A_exp;
typedef struct A_expList_ *A_expList;
typedef enum {A_plus, A_minus, A_times, A_div} A_binop;

struct A_stm_ {
    enum {A_compoundStm ,A_assignStm, A_printStm} kind;
    union {
        struct {A_stm stm1, stm2;} compound;
        struct {string id; A_exp exp;} assign;
        struct {A_expList exps;} print;
    } u;
};
// Constructors for A_stm
A_stm A_CompoundStm(A_stm stm1, A_stm stm2);
A_stm A_AssignStm(string id, A_exp exp);
A_stm A_PrintStm(A_expList exps);

struct A_exp_ {
    enum {A_idExp, A_numExp, A_opExp, A_eseqExp} kind; // Enums inside structs work differently in C++, should I write in C just like in the book?
    union {
        string id;
        int num;
        struct {A_exp left; A_binop oper; A_exp right;} op;
        struct {A_stm stm; A_exp exp;} eseq;
    } u;
};
// Constuctors for A_exp
A_exp A_IdExp(string id);
A_exp A_NumExp(int num);
A_exp A_OpExp(A_exp left, A_binop oper, A_exp right);
A_exp A_EseqExp(A_stm stm, A_exp exp);

struct A_expList_ {
    enum {A_pairExpList, A_lastExpList} kind;
    union {
        struct {A_exp head; A_expList tail; } pair;
        A_exp last;
    } u;
};


// I'll just implement all those constructors above here, instead of in a separate .pp file

A_stm A_CompoundStm(A_stm stm1, A_stm stm2) {
    A_stm ret = (A_stm) checked_malloc(sizeof *ret); // Should Explicitly cast in C++ :/ // A_stm is A_stm_*, hence we can use *ret to refer to the actual struct, not the pointer.
    ret -> kind = A_stm_::A_compoundStm; //WHY
    ret -> u.compound.stm1 = stm1;
    ret -> u.compound.stm2 = stm2;
    return ret;
}
