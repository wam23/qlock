window.onload = currentTime;
var timer;

function currentTime() {
    timer = setInterval(() => {
        var d = new Date();
        document.getElementById('time').textContent = d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds();
    }, 1000);
}
