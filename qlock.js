window.onload = currentTime;
var timer;

function currentTime() {
    timer = setInterval(() => {
        var d = new Date();
        document.getElementById('time').textContent = d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds();
    }, 1000);

    esIst();
    zwoelf();
    uhr();
}

function led(start, length) {
    for (var i = start; i < start + length; i++) {
        document.getElementById("led_" + i).style.color = "magenta";
    }
}

function allOff() {
    for (var i = 0; i < 110; i++) {
        document.getElementById("led_" + i).style.color = "black";
    }
}

function esIst() {
    led(0, 2);
    led(3, 4)
}

function eins() {

}

function zwei() {

}

function drei() {

}

function vier() {

}

function fuenf() {

}

function sechs() {

}

function sieben() {

}

function acht() {

}

function neun() {

}

function zehn() {

}

function elf() {

}

function zwoelf() {
    led(104, 6);
}

function uhr() {
    led(99, 3);
}
