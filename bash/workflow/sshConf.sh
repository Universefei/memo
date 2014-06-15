#!/usr/bin/env bash

ssh-keygen

ssh-copy-id -i root@svn

ssh root@svn

logout
