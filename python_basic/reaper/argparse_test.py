#!/usr/bin/python
import argparse

parser = argparse.ArgumentParser(description='Process some integers.')

args = parser.parse_args()
print(args.accumulate(args.integers))
