#pragma once

typedef struct A_stm_ *A_stm;
typedef struct A_exp_ *A_exp;
typedef struct A_expList_ *A_expList;
typedef enum {A_plus, A_minus, A_times, A_div} A_binop;

// Had to do this so I would not write A_stm_ in the future as it's not supposed to be used outside this file.
typedef enum {A_compoundStm ,A_assignStm, A_printStm} A_stm_kind;
struct A_stm_ {
    A_stm_kind kind;
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

typedef enum {A_idExp, A_numExp, A_opExp, A_eseqExp} A_exp_kind;
struct A_exp_ {
    A_exp_kind kind; // Enums inside structs work differently in C++, should I write in C just like in the book?
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

typedef enum {A_pairExpList, A_lastExpList} A_expList_kind;
struct A_expList_ {
    A_expList_kind kind;
    union {
        struct {A_exp head; A_expList tail; } pair;
        A_exp last;
    } u;
};

A_expList A_PairExpList(A_exp head, A_expList tail);
A_expList A_LastExpList(A_exp last);
// I'll just implement all those constructors above here, instead of in a separate .pp file

A_stm A_CompoundStm(A_stm stm1, A_stm stm2) {
    A_stm ret = (A_stm) checked_malloc(sizeof *ret); // Should Explicitly cast in C++ :/ // A_stm is A_stm_*, hence we can use *ret to refer to the actual struct, not the pointer.
    ret -> kind = A_compoundStm; //Yep had to do workaround for this, see definition of enums above
    ret -> u.compound.stm1 = stm1;
    ret -> u.compound.stm2 = stm2;
    return ret;
}
A_stm A_AssignStm(string id, A_exp exp) {
    A_stm ret = (A_stm) checked_malloc(sizeof *ret);
    ret -> kind = A_assignStm;
    ret -> u.assign.id = id;
    ret -> u.assign.exp = exp;
    return ret;
}
A_stm A_PrintStm(A_expList exps){
    A_stm ret = (A_stm) checked_malloc(sizeof *ret);
    ret -> kind = A_printStm;
    ret -> u.print.exps = exps;
    return ret;
}

A_exp A_IdExp(string id){
    A_exp ret = (A_exp) checked_malloc(sizeof *ret);
    ret -> kind = A_idExp;
    ret -> u.id = id;
    return ret;
}
A_exp A_NumExp(int num){
    A_exp ret = (A_exp) checked_malloc(sizeof *ret);
    ret -> kind = A_numExp;
    ret -> u.num = num;
    return ret;
}
A_exp A_OpExp(A_exp left, A_binop oper, A_exp right){
    A_exp ret = (A_exp) checked_malloc(sizeof *ret);
    ret -> kind = A_opExp;
    ret -> u.op.left = left;
    ret -> u.op.oper = oper;
    ret -> u.op.right = right;
    return ret;
}
A_exp A_EseqExp(A_stm stm, A_exp exp){
    A_exp ret = (A_exp) checked_malloc(sizeof *ret);
    ret -> kind = A_eseqExp;
    ret -> u.eseq.stm = stm;
    ret -> u.eseq.exp = exp;
    return ret;
}


A_expList A_PairExpList(A_exp head, A_expList tail) {
    A_expList ret = (A_expList) checked_malloc(sizeof *ret);
    ret -> kind = A_pairExpList;
    ret -> u.pair.head = head;
    ret -> u.pair.tail = tail;
    return tail;
}
A_expList A_LastExpList(A_exp last){
    A_expList ret = (A_expList) checked_malloc(sizeof *ret);
    ret -> kind = A_lastExpList;
    ret -> u.last = last;
    return ret;
}
