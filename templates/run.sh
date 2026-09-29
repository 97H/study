#!/usr/bin/env bash
# 사용법: ./run.sh path/to/solution.cpp
# g++로 컴파일 후 바로 실행 (프로그래머스 채점 환경과 유사하게 -O2, c++17 기준)
set -e
if [ -z "$1" ]; then
  echo "사용법: $0 <cpp파일경로>"
  exit 1
fi

SRC="$1"
BIN="/tmp/$(basename "${SRC%.cpp}")"

g++ -std=c++17 -O2 -Wall -Wextra -o "$BIN" "$SRC"
echo "----- 컴파일 성공, 실행 -----"
"$BIN"
