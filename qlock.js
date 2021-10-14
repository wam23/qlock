window.onload = currentTime;
var timer;

function currentTime() {
    timer = setInterval(() => {
        var d = new Date();
        document.getElementById('time').textContent = d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds();
        updateTime(d.getHours(), d.getMinutes());
    }, 1000);
}

function updateTime(hour, minutes) {
    esIst();

    switch (Math.floor(minutes / 5)) {
        case 0:
            //uhr();
            break;
        case 1:
            m5();
            break;
        case 2:
            m10();
            break;
        case 3:
            m15();
            break;
        case 4:
            m20();
            break;
        case 5:
            m25();
            break;
        case 6:
            m30();
            break;
        case 7:
            m35();
            break;
        case 8:
            m40();
            break;
        case 9:
            m45();
            break;
        case 10:
            m50();
            break;
        case 11:
            m55();
            break;
    }

    if (minutes > 22) {
        hour++;
    }

    switch (hour % 12) {
        case 0:
            h12();
            break;
        case 1:
            h1();
            break;
        case 2:
            h2();
            break;
        case 3:
            h3();
            break;
        case 4:
            h4();
            break;
        case 5:
            h5();
            break;
        case 6:
            h6();
            break;
        case 7:
            h7();
            break;
        case 8:
            h8();
            break;
        case 9:
            h9();
            break;
        case 10:
            h10();
            break;
        case 11:
            h11();
            break;
    }
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
    led(3, 4);
}

function m5() {
    led(8, 3);
    led(42, 2);
}

function m10() {
    led(11, 3);
    led(42, 2);
}

function m15() {
    led(16, 6);
    led(42, 2);
}

function m20() {
    led(22, 6);
    led(42, 2);
}

function m25() {
    led(8, 3);
    led(30, 3);
    led(36, 5);
}

function m30() {
    led(36, 5);
}

function m35() {
    led(8, 3);
    led(42, 2);
    led(36, 5);
}

function m40() {
    led(22, 6);
    led(30, 3);
}

function m45() {
    led(16, 6);
    led(30, 3);
}

function m50() {
    led(11, 3);
    led(30, 3);
}

function m55() {
    led(8, 3);
    led(30, 3);
}

function h1() {
    led(44, 3);
}

function h2() {
    led(47, 4);
}

function h3() {
    led(52, 3);
}

function h4() {
    led(61, 5);
}

function h5() {
    led(57, 4);
}

function h6() {
    led(66, 6);
}

function h7() {
    led(72, 5);
}

function h8() {
    led(83, 5);
}

function h9() {
    led(79, 4);
}

function h10() {
    led(88, 4);
}

function h11() {
    led(95, 4);
}

function h12() {
    led(104, 6);
}

function uhr() {
    led(99, 3);
}
