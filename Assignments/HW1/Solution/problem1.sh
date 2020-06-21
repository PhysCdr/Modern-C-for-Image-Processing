#!/usr/bin/bash

echo "Lines in file: " $(wc -l data/data.dat)

echo "Lines with d[a/o]lor: " $(grep d[a,o]lor data/data.dat -c)

echo "Words " $(wc -w data/data.dat)

echo "Words starting with mol " $(grep mol data/data.dat -c)

echo "Number of txt files " $(ls data/test_folder | grep .txt$ -c)