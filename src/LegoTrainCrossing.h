#ifndef LegoTrainCrossing_h
#define LegoTrainCrossing_h

#include "Arduino.h"
#include "Servo.h"

typedef void (*CallBackFunction) ();

class LegoTrainCrossing {
   public:
      typedef enum {
        CLOSED = 0,
        OPENED = 1
      } State;

      typedef enum {
        EXITED   = 0,
        EXITING  = 1,
        ENTERED  = 2,
        ENTERING = 3
      } TrainDetectionState;

      LegoTrainCrossing(byte[] barrierPins, LegoTrainDetector[] detectors);

      void closeBarriers();
      void openBarriers();

      void detectTrain();
   private:
      Servo[] _barriers;
      LegoTrainDetector[] _detectors;
};

#endif
