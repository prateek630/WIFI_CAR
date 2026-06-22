// =====================
// MOTOR PINS
// =====================

// Front Right Motor
#define R_IN1 2
#define R_IN2 3

// Rear Right Motor
#define R_IN3 4
#define R_IN4 5

// Front Left Motor
#define L_IN1 6
#define L_IN2 7

// Rear Left Motor
#define L_IN3 8
#define L_IN4 9

//#define LEFT_PWM 10
//#define RIGHT_PWM 11

String cmd = "";

// =====================
// SETUP
// =====================

void setup()
{
    Serial.begin(115200);

    pinMode(R_IN1, OUTPUT);
    pinMode(R_IN2, OUTPUT);
    pinMode(R_IN3, OUTPUT);
    pinMode(R_IN4, OUTPUT);

    pinMode(L_IN1, OUTPUT);
    pinMode(L_IN2, OUTPUT);
    pinMode(L_IN3, OUTPUT);
    pinMode(L_IN4, OUTPUT);

  //  pinMode(LEFT_PWM, OUTPUT);
   // pinMode(RIGHT_PWM, OUTPUT);

    stopMotors();
}

// =====================
// LOOP
// =====================

void loop()
{
    while (Serial.available())
    {
        char c = Serial.read();

        if (c == '\n')
        {
            cmd.trim();

            if (cmd == "FW")
            {
            //    analogWrite(LEFT_PWM, 180);
            //   analogWrite(RIGHT_PWM, 180);
                fw();
            }
            else if (cmd == "BW")
            {
            //    analogWrite(LEFT_PWM, 180);
            //    analogWrite(RIGHT_PWM, 180);
                bw();
            }
            else if (cmd == "LW")
            {
              //  analogWrite(LEFT_PWM, 180);
                //analogWrite(RIGHT_PWM, 180);
                lw();
            }
            else if (cmd == "RW")
            {
                //analogWrite(LEFT_PWM, 180);
                //analogWrite(RIGHT_PWM, 180);
                rw();
            }
            else if (cmd == "FL")
            {
              //  analogWrite(LEFT_PWM, 180);
               // analogWrite(RIGHT_PWM, 180);
                fl();
            }
            else if (cmd == "FR")
            {
               // analogWrite(LEFT_PWM, 180);
               // analogWrite(RIGHT_PWM, 180);
                fr();
            }
            else if (cmd == "BL")
            {
               // analogWrite(LEFT_PWM, 180);
               // analogWrite(RIGHT_PWM, 180);
                bl();
            }
            else if (cmd == "BR")
            {
               // analogWrite(LEFT_PWM, 180);
               // analogWrite(RIGHT_PWM, 180);
                br();
            }
            else if (cmd == "CW")
            {
               // analogWrite(LEFT_PWM, 180);
               // analogWrite(RIGHT_PWM, 180);
                cw();
            }
            else if (cmd == "CC")
            {
               // analogWrite(LEFT_PWM, 180);
               // analogWrite(RIGHT_PWM, 180);
                cc();
            }
            else if (cmd == "FCW")
            {
                fcw();
            }
            else if (cmd == "FCC")
            {
                fcc();
            }
            else if (cmd == "BCW")
            {
                bcw();
            }
            else if (cmd == "BCC")
            {
                bcc();
            }
            
            else if (cmd == "ST")
            {
               // analogWrite(LEFT_PWM, 0);
               // analogWrite(RIGHT_PWM, 0);
                stopMotors();
            }
            cmd = "";            
        }
        else
        {
            cmd += c;
        }
    }
}

// =====================
// MOVEMENTS
// =====================

void fw()
{
    // All Forward

    digitalWrite(R_IN1, HIGH);
    digitalWrite(R_IN2, LOW);

    digitalWrite(R_IN3, HIGH);
    digitalWrite(R_IN4, LOW);

    digitalWrite(L_IN1, HIGH);
    digitalWrite(L_IN2, LOW);

    digitalWrite(L_IN3, HIGH);
    digitalWrite(L_IN4, LOW);
}

void bw()
{
    // All Backward

    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, HIGH);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, HIGH);

    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, HIGH);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, HIGH);
}

void cw()
{
    // Clockwise Rotation

    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, HIGH);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, HIGH);

    digitalWrite(L_IN1, HIGH);
    digitalWrite(L_IN2, LOW);

    digitalWrite(L_IN3, HIGH);
    digitalWrite(L_IN4, LOW);
}

void cc()
{
    // Counter Clockwise Rotation

    digitalWrite(R_IN1, HIGH);
    digitalWrite(R_IN2, LOW);

    digitalWrite(R_IN3, HIGH);
    digitalWrite(R_IN4, LOW);

    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, HIGH);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, HIGH);
}

void fl()
{
    digitalWrite(R_IN1, HIGH);
    digitalWrite(R_IN2, LOW);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, LOW);

    digitalWrite(L_IN1, HIGH);
    digitalWrite(L_IN2, LOW);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, LOW);
}

void fr()
{
    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, LOW);

    digitalWrite(R_IN3, HIGH);
    digitalWrite(R_IN4, LOW);

    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, LOW);

    digitalWrite(L_IN3, HIGH);
    digitalWrite(L_IN4, LOW);
}

void br()
{
    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, HIGH);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, LOW);

    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, HIGH);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, LOW);
}

void bl()
{
    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, LOW);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, HIGH);

    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, LOW);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, HIGH);
}

void lw()
{
    // Strafe Left (mecanum)
    
    digitalWrite(L_IN1, HIGH);
    digitalWrite(L_IN2, LOW);

    digitalWrite(R_IN1, HIGH);
    digitalWrite(R_IN2, LOW);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, HIGH);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, HIGH);

}

void rw()
{
    // Strafe Right (mecanum)
    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, HIGH);

    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, HIGH);

    digitalWrite(L_IN3, HIGH);
    digitalWrite(L_IN4, LOW);

    digitalWrite(R_IN3, HIGH);
    digitalWrite(R_IN4, LOW);
}
void fcw()
{
    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, LOW);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, LOW);

    digitalWrite(L_IN1, HIGH);
    digitalWrite(L_IN2, LOW);

    digitalWrite(L_IN3, HIGH);
    digitalWrite(L_IN4, LOW);
}
void fcc()
{
    digitalWrite(R_IN1, HIGH);
    digitalWrite(R_IN2, LOW);

    digitalWrite(R_IN3, HIGH);
    digitalWrite(R_IN4, LOW);

    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, LOW);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, LOW);
}
void bcc()
{
    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, HIGH);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, HIGH);

    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, LOW);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, LOW);
}
void bcw()
{
    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, LOW);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, LOW);

    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, HIGH);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, HIGH);
}
void stopMotors()
{
    digitalWrite(R_IN1, LOW);
    digitalWrite(R_IN2, LOW);

    digitalWrite(R_IN3, LOW);
    digitalWrite(R_IN4, LOW);

    digitalWrite(L_IN1, LOW);
    digitalWrite(L_IN2, LOW);

    digitalWrite(L_IN3, LOW);
    digitalWrite(L_IN4, LOW);
}

