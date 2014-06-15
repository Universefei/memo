#!/usr/bin/env python
import sys
import gtk
import appindicator

import imaplib
import re
import os

PING_FREQUENCY = 10 # seconds

class CheckGMail:
    def __init__(self):
        self.ind = appindicator.Indicator("new-gmail-indicator",
                "indicator-messages",
                #appindicator.CATEGORY_APPLICATION_STATUS)
                #appindicator.CATEGORY_COMMUNICATIONS)
                appindicator.CATEGORY_OTHER)
        self.ind.set_status(appindicator.STATUS_ACTIVE)
        self.ind.set_attention_icon("new-messages-red")

        self.menu_setup()
        self.ind.set_menu(self.menu)

    def menu_setup(self):
        self.menu = gtk.Menu()

        item_list = [(u'Quit', self.quit),
                     (u'Read', self.read)
                     ]
        for text, callback in item_list:
            single_item = gtk.MenuItem(text)
            single_item.connect("activate", callback)
            single_item.show()
            self.menu.append(single_item)

        # multiple line comments
        '''
        self.quit_item = gtk.MenuItem("Quit")
        self.quit_item.connect("activate", self.quit)
        self.quit_item.show()
        self.menu.append(self.quit_item)

        self.to_read = gtk.MenuItem("Read")
        self.to_read.connect("activate", self.read)
        self.to_read.show()
        self.menu.append(self.to_read)
        '''

    def main(self):
        #self.check_mail()
        gtk.timeout_add(PING_FREQUENCY * 1000, self.check_mail)
        gtk.main()

    def quit(self, widget):
        #sys.exit(0)
        #os.kill(os.getpid(), 9)
        gtk.main_quit()

    def read(self, widget):
        os.system("xdg-open https://mail.google.com")

    def check_mail(self):
        messages, unread = self.gmail_checker('univfei@gmail.com','421127.feilun')
        if unread > 0:
            self.ind.set_status(appindicator.STATUS_ATTENTION)
        else:
            self.ind.set_status(appindicator.STATUS_ACTIVE)
        return True

    def gmail_checker(self, username, password):
        i = imaplib.IMAP4_SSL('imap.gmail.com')
        try:
            i.login(username, password)
            x, y = i.status('INBOX', '(MESSAGES UNSEEN)')
            messages = int(re.search('MESSAGES\s+(\d+)', y[0]).group(1))
            unseen = int(re.search('UNSEEN\s+(\d+)', y[0]).group(1))
            return (messages, unseen)
        except:
            return False, 0

if __name__ == "__main__":
    indicator = CheckGMail()
    indicator.main()
