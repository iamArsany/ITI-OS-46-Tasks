class AlarmClock extends Clock {
  #alarmTime;
  #anIntervalId;
  #msg = "Alarm is here!!";
  constructor(startTime, alarmTime) {
    super(startTime);
    this.#alarmTime = alarmTime;
  }

  #checkAlarm() {
    console.log(Clock.formatTime(this.hours, this.minutes, this.seconds));
    console.log(this.#alarmTime);
    if (
      Clock.formatTime(this.hours, this.minutes, this.seconds) ==
      this.#alarmTime
    ) {
      console.log(this.#msg);
      super.stop(this.#anIntervalId);
    }
  }

  start() {
    super.start();
    this.#anIntervalId = setInterval(() => {
      this.#checkAlarm();
    }, 1000);
  }

  setALarmTime(alarmTime) {
    this.#alarmTime = alarmTime;
  }

  setNewMessage(msg) {
    this.#msg = msg;
  }
}

let cl = new AlarmClock("12:12:12", "12:12:20");
cl.setALarmTime("12:12:14");
cl.setNewMessage("test new alarm");
cl.start();
