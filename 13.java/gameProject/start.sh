#!/bin/bash

echo "message to test"
javac -d out/ src/game/*.java && java -cp out/ game.Main


