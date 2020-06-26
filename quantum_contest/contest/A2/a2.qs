namespace Solution {
    open Microsoft.Quantum.Intrinsic;

    operation Solve (unitary : (Qubit[] => Unit is Adj+Ctl)) : Int {
        mutable flag = 0;
		using (qs = Qubit[2]) {
			X(qs[0]);
			X(qs[1]);
			unitary(qs);
			if (M(qs[0]) == Zero or M(qs[1]) == Zero) {
				ResetAll(qs);
				X(qs[1]);
				unitary(qs);
				if (M(qs[0]) == One) {
					set flag = 2;
				} else {
					set flag = 1;
				}
			} else {
				X(qs[0]);
				unitary(qs);
				if (M(qs[0]) == One) {
					set flag = 3;
				} else {
					set flag = 0;
				}
			}
			ResetAll(qs);
		}
		return flag;
    }
}
