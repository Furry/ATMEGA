const timer0 = [1, 8, 64, 256, 1024];
const timer1 = [1, 8, 64, 256, 1024];
const timer2 = [1, 8, 32, 64, 128, 256, 1024];

const desiredFrequency = 64;

function calculate(frequencyInHz) {
    const timer0Res = timer0.map(function (prescale) {
        const segments = getFreq(frequencyInHz, prescale).toString().split(".");
        let decimal = 0;
        let whole = parseInt(segments[0]);
        if (segments.length > 1) {
            decimal = parseInt(segments[1].substring(0, 4).padEnd(4, "0"));
        }

        return { key: "timer0", prescale: prescale, whole: whole, decimal: decimal };
    });

    const timer1Res = timer1.map(function (prescale) {
        const segments = getFreq(frequencyInHz, prescale).toString().split(".");
        let decimal = 0;
        let whole = parseInt(segments[0]);
        if (segments.length > 1) {
            decimal = parseInt(segments[1].substring(0, 4).padEnd(4, "0"));
        }

        return { key: "timer1", prescale: prescale, whole: whole, decimal: decimal };
    });

    const timer2Res = timer2.map(function (prescale) {
        const segments = getFreq(frequencyInHz, prescale).toString().split(".");
        let decimal = 0;
        let whole = parseInt(segments[0]);
        if (segments.length > 1) {
            decimal = parseInt(segments[1].substring(0, 4).padEnd(4, "0"));
        }

        return { key: "timer2", prescale: prescale, whole: whole, decimal: decimal };
    });

    // sort timer0Res, timer1Res, and timer2Res by decimal.
    const sorted0 = timer0Res.sort(function (a, b) { return a.decimal - b.decimal; })
    const sorted1 = timer1Res.sort(function (a, b) { return a.decimal - b.decimal; })
    const sorted2 = timer2Res.sort(function (a, b) { return a.decimal - b.decimal; })
    
    console.log(sorted0)
    console.log(sorted1)
    console.log(sorted2)
}

function getFreq(frequencyInHz, prescale) {
    return (16_000_000.0 / (prescale * frequencyInHz) ) - 1.0
}

calculate(desiredFrequency)