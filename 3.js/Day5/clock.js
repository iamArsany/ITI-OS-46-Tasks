class Clock {
  #IntervalId;
  constructor(time) {
    validateClockTimeInput(time);
    this.time = time;
    time = time.split(":");
    time = validateTime(time);
    this.#IntervalId = "";
    this.hours = time[0];
    this.minutes = time[1];
    this.seconds = time[2];
  }

  static formatTime(hours, minutes, seconds) {
    validateTimeValues(hours);
    validateTimeValues(minutes);
    validateTimeValues(seconds);
    let arr = [hours, minutes, seconds];
    return arr.join(":");
  }

  #tick() {
    console.clear();
    this.seconds++;

    if (this.seconds === 60) {
      this.seconds = 0;
      this.minutes++;

      if (this.minutes === 60) {
        this.minutes = 0;
        this.hours++;

        if (this.hours === 24) {
          this.hours = 0;
        }
      }
    }
    // console.log(Clock.formatTime(this.hours, this.minutes, this.seconds));
  }

  start() {
    this.#IntervalId = setInterval(() => {
      this.#tick();
    }, 1000);
  }
  stop() {
    clearInterval(this.#IntervalId);
  }
  getTime() {
    return Clock.formatTime(this.hours, this.minutes, this.seconds);
  }
}

//helper
const validateTime = function (timeArr) {
  for (let elem in timeArr) {
    if (Number(timeArr[elem])) {
      timeArr[elem] = Number(timeArr[elem]);
    } else {
      throw new Error("Not Valid Time");
    }
  }
  return timeArr;
};

const validateTimeValues = function (val) {
  if (typeof val != typeof 1) {
    throw new Error("Enter a valid Number");
  }
};

const validateClockTimeInput = function (time) {
  if (time == "") {
    throw new Error("Provide Constructor Values");
  }
  if (time.split(":").length < 2) {
    throw new Error("Provide Constructor Value correctly");
  }
};

// try of in , with objects
