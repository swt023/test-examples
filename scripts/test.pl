#!/usr/bin/perl  -w

print a * 5 . "\n";
$arr[0] = 'aaa';
$arr[1] = 'bbb';
$arr[9] = 'hhhh';

print '0' . $arr[0] . '1' . $arr[1] . '2' . $arr[2] . '3' . $arr[3] . '###' . $arr[$#arr] . "\n";
print $#arr . "\n";

@fred = qw(eating rocks is wrong);
$fred = "right";
print "this is $fred[3]\n";
print "this is ${fred}[3]\n";
print "this is $fred". "[3]\n";
print "this is $fred\[3]\n";
