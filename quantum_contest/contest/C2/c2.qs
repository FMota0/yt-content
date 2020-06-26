namespace Solution {
    open Microsoft.Quantum.Intrinsic;
	open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], parity : Int) : Unit {
        let len = Length(qs);
		mutable flag = 0;
		repeat {
			using (aux = Qubit()) {
				ResetAll(qs);
				ApplyToEach(H, qs);
				for (index in 0..(len - 1)) {
					Controlled X([qs[index]], aux);
				}
				if (parity == 0) {
					if (M(aux) == Zero) {
						set flag = 1;
					}
				} else {
					if (M(aux) == One) {
						set flag = 1;
					}
				}
				Reset(aux);
			}
		} until (flag == 1);
    }
}