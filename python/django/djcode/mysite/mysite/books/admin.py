from django.contrib import admin
from mysite.books.models import Publisher, Author, Book

# Register your models here.

admin.site.register(Publisher)
admin.site.register(Author)
admin.site.register(Book)
