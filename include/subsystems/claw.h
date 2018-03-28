#ifndef _SUBSYSTEMS_CLAW_H_
#define _SUBSYSTEMS_CLAW_H_

class Claw {
  private:
    Claw();
    static Claw* instance;
  public:
    void setClaw(int speed);
    static Claw* getInstance();
};

#endif
