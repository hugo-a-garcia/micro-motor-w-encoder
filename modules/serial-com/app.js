/*
/ Simple program to send key strokes via the serial port.
/ This is a command line interface.
*/

const readline = require('readline');
const SerialPort = require('serialport');

//Serial Port

const port = new SerialPort("/dev/ttyACM0", {
    baudRate: 115200
});

//Read from Serial Port

const ReadlineParser = SerialPort.parsers.Readline;

const parser = new ReadlineParser
port.pipe(parser);
parser.on("data", async (data) => {
    console.log(data)
});

// port.on('readable', function () {
//     console.log(port.read().toString());
// });

port.on('error', function (err) {
    console.log('Error: ', err.message);
});

//Write to serial port

function serialWrite(output) {
    
    port.write(output, function (err) {
        if (err) {
            return console.log('Error on write: ', err.message)
        }
        console.log('message written')
    })

    // Open errors will be emitted as an error event
    port.on('error', function (err) {
        console.log('Error: ', err.message)
    })
}

//Command line interface setup

var stdin = process.stdin;

const rl = readline.createInterface({
    input: stdin,
    output: process.stdout
});
rl.prompt();

readline.emitKeypressEvents(stdin);
stdin.setRawMode(true);
stdin.resume();

// Parse cursor keys and send a digit over serial.

stdin.on('keypress', function (ch, key) {
    console.log('got "keypress"', key);
    if (key && key.ctrl && key.name == 'c') {
        stdin.pause();
    }

    switch (key.name) {
        case "space":
            //console.log("STOP");
            serialWrite("1");
            break;
        case 'up':
            //console.log("UP");
            serialWrite("2");
            break;
        case 'down':
            serialWrite("3");
            //console.log("DOWN");
            break;
        case 'left':
            serialWrite("4");
            //console.log('LEFT');
            break;
        case 'right':
            serialWrite("5");
            //console.log('RIGHT')
        default:
            break;
    }

});
