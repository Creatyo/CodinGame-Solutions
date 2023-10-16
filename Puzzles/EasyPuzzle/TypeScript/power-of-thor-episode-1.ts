/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/

var inputs: string[] = readline().split(' ');
const lightX: number = parseInt(inputs[0]); // the X position of the light of power
const lightY: number = parseInt(inputs[1]); // the Y position of the light of power
const initialTx: number = parseInt(inputs[2]); // Thor's starting X position
const initialTy: number = parseInt(inputs[3]); // Thor's starting Y position

var distanceX : number = Math.abs(lightX - initialTx);
var distanceY : number = Math.abs(lightY - initialTy);

var move : string = '';

// game loop
while (true) {
    const remainingTurns: number = parseInt(readline()); // The remaining amount of turns Thor can move. Do not remove this line.

    // Write an action using console.log()
    // To debug: console.error('Debug messages...');

    // A single line providing the move to be made: N NE E SE S SW W or NW
    move = '';
    
    if(lightY > initialTy && distanceY > 0)
    {
        move = 'S'
        distanceY --;
    }
    else if(lightY < initialTy && distanceY > 0)
    {
        move = 'N'
        distanceY --;
    }
    if(lightX > initialTx && distanceX > 0)
    {
        move += 'E'
        distanceX --;
    }
    else if(lightX < initialTx && distanceX > 0)
    {
        move += 'W'
        distanceX --;
    }
    console.log(move);
}
