#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int leds[] = {5, 18, 19};
const int buttons[] = {21, 22, 23};
const int freqs[] = {329, 261, 392};
const int buzzerPin = 4;

std::vector<int> sequence;

int playerChoice = 0;
int displayDelay = 400;

unsigned long lastInputTime = 0;
unsigned long timeout = 7500;

enum GameState
{
  SHOW_SEQUENCE,
  PLAYER_INPUT,
  GAME_OVER
};

GameState state = SHOW_SEQUENCE;

void TurnOnLed(int index);
void TurnOffLed(int index);
void PlayTone(int index);
bool IsButtonPressed(int index);
int GetRandomButton();
void AddToSequence();
void LightSequence();
int CheckChoice();
void FlashAllLeds();

void setup()
{
  std::srand(std::time(nullptr));

  for (int led : leds)
    pinMode(led, OUTPUT);

  for (int button : buttons)
    pinMode(button, INPUT_PULLUP);
}

void loop()
{
  switch (state)
  {

    case SHOW_SEQUENCE:

      AddToSequence();
      LightSequence();
      playerChoice = 0;
      lastInputTime = millis();

      state = PLAYER_INPUT;

      break;

    case PLAYER_INPUT:
    {
      int choice = CheckChoice();

      if (millis() - lastInputTime > timeout)
        state = GAME_OVER;

      if (choice != -1)
      {
        lastInputTime = millis();

        if (choice == sequence.at(playerChoice))
        {
          playerChoice++;

          if (playerChoice == sequence.size())
          {
            displayDelay -= 20;
            delay(500);
            state = SHOW_SEQUENCE;
          }
        }
        else
        {
          state = GAME_OVER;
        }
      }
    }
    break;

    case GAME_OVER:

      FlashAllLeds();

      sequence.clear();
      displayDelay = 400;

      state = SHOW_SEQUENCE;

      break;
  }
}

void TurnOnLed(int index)
{
  digitalWrite(leds[index], HIGH);
}

void TurnOffLed(int index)
{
  digitalWrite(leds[index], LOW);
}

void PlayTone(int index) {
  tone(buzzerPin, freqs[index], displayDelay); 
}

bool IsButtonPressed(int index)
{
  return digitalRead(buttons[index]) == LOW;
}

int GetRandomButton()
{
  return std::rand() % 3;
}

void AddToSequence()
{
  sequence.push_back(GetRandomButton());
}

void LightSequence()
{
  for (int i : sequence)
  {
    PlayTone(i);

    TurnOnLed(i);
    delay(displayDelay);
    
    TurnOffLed(i);
    delay(displayDelay);
  }
}

int CheckChoice()
{
  static unsigned long lastPressTime = 0;

  if (millis() - lastPressTime < 50)
    return -1;

  for (int i = 0; i < 3; i++)
  {
    if (IsButtonPressed(i))
    {
      lastPressTime = millis();

      PlayTone(i);

      TurnOnLed(i);
      delay(200);
      TurnOffLed(i);

      return i;
    }
  }

  return -1;
}

void FlashAllLeds()
{
  for (int i = 0; i < 3; i++)
    TurnOnLed(i);

  delay(400);

  for (int i = 0; i < 3; i++)
    TurnOffLed(i);

  delay(400);
}