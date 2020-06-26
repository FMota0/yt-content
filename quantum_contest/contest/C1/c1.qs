namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;
 
    operation Solve (qs : Qubit[]) : Unit {
        mutable flag = 0;
		repeat {
			using(q = Qubit()){
				ResetAll(qs);
				ApplyToEach(H, qs);
				Controlled X(qs, q);
				if (M(q) == Zero) {
					set flag = 1;
				}
				Reset(q);
			}
		} until (flag == 1);
    }
}