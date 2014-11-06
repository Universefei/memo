from django.conf.urls import patterns, include, url
# from django.views.generic.simple import direct_to_template


# urlpatterns = patterns('',
#         url(r'about/$', about_pages),
#         url(r'^aboutnot/$', direct_to_template, 
#             { 'template': 'about.html',
#                 }
#             ),

#         )

urlpatterns = patterns('mysite.login.views',
        url(r'^$', 'about'),
        url(r'^about/$', 'about', name='login_about'),
        url(r'^page/$', 'about', name='login_thispage'),
        )
