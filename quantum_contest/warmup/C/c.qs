namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (qs : Qubit[]) : Unit {
        mutable flag = 0;
        repeat {
            using(q = Qubit()){
                ResetAll(qs);
                H(qs[0]);
                H(qs[1]);
                Controlled X(qs, q);
                if (M(q) == Zero) {
                    set flag = 1;
                }
                Reset(q);
            }
        } until (flag == 1);
        X(qs[0]);
        X(qs[1]);
    }
}