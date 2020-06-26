namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.Canon;

    operation Increment(qarray : Qubit[]) : Unit is Adj+Ctl {
        if (Length(qarray) > 1) {
            (Controlled Increment)([qarray[0]], qarray[1 ...]);
        }
        X(qarray[0]);
    }

    operation Solve (inputs : Qubit[], output : Qubit) : Unit is Adj+Ctl {
        using (counter = Qubit[4]) {
            let len = Length(inputs);
            for (i in 0..(len - 1)) {
                (Controlled Increment)([inputs[i]], counter);
                X(inputs[i]);
                (Controlled Adjoint Increment)([inputs[i]], counter);
                X(inputs[i]);
            }
            for (i in 0..3) {
                X(counter[i]);
            }
            (Controlled X)(counter, output);
            for (i in 0..3) {
                X(counter[i]);
            }
            for (i in 0..(len - 1)) {
                (Controlled Adjoint Increment)([inputs[i]], counter);
                X(inputs[i]);
                (Controlled Increment)([inputs[i]], counter);
                X(inputs[i]);
            }
        }
    }
}