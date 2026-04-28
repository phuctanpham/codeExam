#!/bin/bash
# ============================================
# build.sh - Script tự động build cFraction
# name: Pham Tan Phuc
# id: 25730134
# dob: 240290
# class: IT002.F21.CN1.CNTT
# ============================================

# Dừng ngay nếu có lỗi
set -e

PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$PROJECT_DIR/build"

echo ">>> Xoa thu muc build cu (neu co)..."
rm -rf "$BUILD_DIR"

echo ">>> Tao thu muc build moi..."
mkdir "$BUILD_DIR"

echo ">>> Chay cmake..."
cmake -S "$PROJECT_DIR" -B "$BUILD_DIR"

echo ">>> Bien dich..."
cmake --build "$BUILD_DIR"

echo ""
echo ">>> Build thanh cong! Chay chuong trinh:"
echo "    ./build/fraction_app"
