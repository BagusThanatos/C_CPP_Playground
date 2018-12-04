#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "slp.h"

inline int maxFrom(int a, 
                   int b) {
    return a > b ? a : b;
}

int maxargs(A_stm stm) {
    if (stm -> kind == A_assignStm) {
        if (stm -> u.assign.exp -> kind == A_eseqExp) 
            return maxargs(stm -> u.assign.exp -> u.eseq.stm);
        return 0;
    }
    if (stm -> kind == A_compoundStm) 
        return maxFrom(
        maxargs(stm-> u.compound.stm1),
        maxargs(stm -> u.compound.stm2));
    // stm -> kind == A_printStm
    A_expList list = stm -> u.print.exps;
    printf("kind: %d\n", list -> kind);
    printf("A_pairExpList: %d\n", A_pairExpList);
    if (list -> kind == A_pairExpList) return 2;
    return 1;
}

int main() {
    A_stm prog = A_CompoundStm(A_AssignStm("a", A_OpExp(A_NumExp(5), A_plus, A_NumExp(3))),
                               A_CompoundStm(A_AssignStm("b", A_EseqExp(A_PrintStm(A_PairExpList(A_IdExp("a"),
                                                                                                 A_LastExpList(A_OpExp(A_IdExp("a"), A_minus, A_NumExp(1))))),
                                                                        A_OpExp(A_NumExp(10), A_times, A_IdExp("a")))),
                                             A_PrintStm(A_LastExpList(A_IdExp("b")))));
    assert(prog);
    printf("%d\n", maxargs(prog));
    return 0;
}
