/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

const n: number = parseInt(readline()); // the number of temperatures to analyse
if(n > 0){
    var inputs: string[] = readline().split(' ');
    var temp : number = parseInt(inputs[0])
    for (let i = 1; i < n; i++) {
        const t: number = parseInt(inputs[i]);// a temperature expressed as an integer ranging from -273 to 5526
        if((Math.abs(temp) === Math.abs(t)) && temp < t){
            temp = t;
        }
        else if((temp < t) && t <= 0){
            temp = t;
        }
        else if((temp > t) && t >= 0){
            temp = t;
        }
    }

    // Write an answer using console.log()
    // To debug: console.error('Debug messages...');

    console.log(temp);
}
else{
    console.log('0');
}
