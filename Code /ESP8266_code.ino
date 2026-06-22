#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WebSocketsServer.h>

ESP8266WebServer server(80);
WebSocketsServer webSocket(81);
String currentCmd = "ST";
const char page[] PROGMEM = R"rawliteral(

<!DOCTYPE html>
<html>
<head>

<meta name="viewport"
content="width=device-width,
initial-scale=1.0,
maximum-scale=1.0,
user-scalable=no">
<meta name="apple-mobile-web-app-capable" content="yes">
<meta name="apple-mobile-web-app-status-bar-style" content="black-translucent">
<meta name="apple-mobile-web-app-title" content="RoboCar">

<style>

html,body{
    margin:0;
    padding:0;
    width:100%;
    height:100%;
    overflow:hidden;

    background:#f0f0f0;

    touch-action:none;
    user-select:none;
    -webkit-user-select:none;
    -webkit-touch-callout:none;

    font-family:Arial;
}

.container{
    width:100vw;
    height:100vh;

    display:flex;
    flex-direction:row;

    justify-content:space-evenly;
    align-items:center;
}

.rotate-panel{
    display:flex;
    flex-direction:row;
    gap:15px;
}

.move-panel{
    display:flex;
    flex-direction:column;
}

.row{
    display:flex;
    justify-content:center;
    align-items:center;
}

button{

    width:16vw;
    height:18vh;

    margin:5px;

    font-size:24px;
    font-weight:bold;

    border:none;
    border-radius:15px;

    background:white;

    touch-action:none;
}
.rotate-btn{
    width:22vw;
    height:30vh;

    font-size:32px;
}

.empty{
    width:16vw;
    height:18vh;
    margin:5px;
}
.rotate-panel{
    display:flex;
    flex-direction:row;
    gap:8px;
}

</style>

</head>

<body>

<div class="container">

    <!-- Rotation Buttons -->
    <div class="rotate-panel">
        <button id="cc" class="rotate-btn">CC</button>
        <button id="cw" class="rotate-btn">CW</button>
    </div>

    <!-- Movement Buttons -->
    <div class="move-panel">

        <div class="row">
            <button id="fl">FL</button>
            <button id="fw">FW</button>
            <button id="fr">FR</button>
        </div>

        <div class="row">
            <button id="lw">LW</button>
            <div class="empty"></div>
            <button id="rw">RW</button>
        </div>

        <div class="row">
            <button id="bl">BL</button>
            <button id="bw">BW</button>
            <button id="br">BR</button>
        </div>

    </div>

</div>

<script>

var ws = new WebSocket("ws://" + location.hostname + ":81/");

function bind(id,cmd)
{
    let btn = document.getElementById(id);

    btn.addEventListener("touchstart",function(e){
        e.preventDefault();
        ws.send(cmd);
    });

    btn.addEventListener("touchend",function(e){
        e.preventDefault();
        ws.send("ST");
    });

    btn.addEventListener("mousedown",function(e){
        e.preventDefault();
        ws.send(cmd);
    });

    btn.addEventListener("mouseup",function(e){
        e.preventDefault();
        ws.send("ST");
    });

    btn.addEventListener("mouseleave",function(){
        ws.send("ST");
    });
}

bind("fw","FW");
bind("bw","BW");

bind("lw","LW");
bind("rw","RW");

bind("fl","FL");
bind("fr","FR");

bind("bl","BL");
bind("br","BR");

bind("cw","CW");
bind("cc","CC");

document.addEventListener('gesturestart', function(e){
    e.preventDefault();
});

document.addEventListener('dblclick', function(e){
    e.preventDefault();
});

document.addEventListener('contextmenu', function(e){
    e.preventDefault();
});

</script>

</body>
</html>

)rawliteral";

void handleRoot()
{
    server.send(200, "text/html", page);
}

void webSocketEvent(
    uint8_t num,
    WStype_t type,
    uint8_t * payload,
    size_t length)
{
    if(type == WStype_TEXT)
    {
        currentCmd = (char*)payload;
    }
}

void setup()
{
    Serial.begin(115200);

    WiFi.softAP("RoboCar","12345678");

    Serial.println();
    Serial.println("WiFi AP Started");
    Serial.println(WiFi.softAPIP());

    server.on("/", handleRoot);
    server.begin();

    webSocket.begin();
    webSocket.onEvent(webSocketEvent);

    Serial.println("Ready");
}

void loop()
{
    server.handleClient();
    webSocket.loop();

    Serial.println(currentCmd);

    delay(20);
}
