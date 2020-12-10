#include <iostream>

using namespace std;

class MobileAlertState;
class AlertStateContext;
class Vibration;
class Silent;

class MobileAlertState {
public:
	virtual void alert(AlertStateContext *ctx) = 0;
	virtual void alertType() = 0;
  virtual void alertType2() = 0;

  virtual ~MobileAlertState() {}
};

class Vibration : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "vibration...\n";
	}
	void alertType() {
		cout << "Set to Vibration Type\n";
	}
  void alertType2() {
    cout << "\n";
  }
};

class Silent : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "silent...\n";
	}
	void alertType() {
		cout << "Set to Silent Type\n";
	}
  void alertType2() {
    cout << "\n";
  }
};

class Ringer : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "ring ring ring...\n";
	}
	void alertType() {
		cout << "Set to Ringer Type\n";
	}
  void alertType2() {
    cout << "\n";
  }
};

class Text : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Incoming text\n\n";
	}
	void alertType() {
		cout << "View Text\n\n";
	}
  void alertType2() {
    cout << "Ignore Text\n\n";
  }
};

class Call : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Incoming Call\n\n";
	}
	void alertType() {
		cout << "Recieve Call\n\n";
	}
  void alertType2() {
    cout << "Ignore Call\n\n";
  }
};
class Email: public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Newly Recieved Email\n\n";
	}
	void alertType() {
		cout << "View Enail?\n\n";
	}
  void alertType2() {
    cout << "Ignore Email Notification?\n\n";
  }
};

class genNote : public MobileAlertState {
public:
	void alert(AlertStateContext *ctx) {
		cout << "Incoming Notification\n\n";
	}
	void alertType() {
		cout << "View Notification\n\n";
	}
  void alertType2() {
    cout << "Ignore Notification\n\n";
  }
};

class AlertStateContext {
private:
	MobileAlertState *currentState;

public:
	AlertStateContext(MobileAlertState *state) {
		currentState = state;
	}

	void setState(MobileAlertState *state) {
		currentState = state;
	}

	MobileAlertState *getState() {
		return currentState;
	}

	void alert() {
		currentState->alert(this);
	}
};

int main() {
  MobileAlertState* vibrate = new Vibration;
	AlertStateContext *stateContext = new AlertStateContext(vibrate);
	stateContext->getState()->alertType();
	stateContext->alert();
	//stateContext->alert();
  MobileAlertState* silent = new Silent;
	stateContext->setState(silent);
	stateContext->getState()->alertType();
	stateContext->alert();
//	stateContext->alert();
//	stateContext->alert();
  MobileAlertState* ringer = new Ringer;
  stateContext->setState(ringer);
	stateContext->getState()->alertType();
	stateContext->alert();
//	stateContext->alert();
	//stateContext->alert();
MobileAlertState* text = new Text;
	stateContext->setState(text);
  stateContext->alert();
	stateContext->getState()->alertType();
  stateContext->getState()->alertType2();	//stateContext->alert();

  MobileAlertState* call = new Call;
	stateContext->setState(call);
  stateContext->alert();
	stateContext->getState()->alertType();
  stateContext->getState()->alertType2();	//stateContext->alert();

  MobileAlertState* email = new Email;
	stateContext->setState(email);
  stateContext->alert();
	stateContext->getState()->alertType();
  stateContext->getState()->alertType2();	

MobileAlertState* gn = new genNote;
	stateContext->setState(gn);
  stateContext->alert();
	stateContext->getState()->alertType();
  stateContext->getState()->alertType2();	
  
  stateContext->setState(silent);
	stateContext->getState()->alertType();
	stateContext->alert();
//	stateContext->alert();
//	stateContext->alert();
  delete silent;
  stateContext->setState(vibrate);
	stateContext->getState()->alertType();
	stateContext->alert();
//	stateContext->alert();
//	stateContext->alert();
  delete vibrate;
  



}