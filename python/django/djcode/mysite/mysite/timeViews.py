
## locals() return a map that contains all local variables and its value

from django.shortcuts import render_to_response
import datetime

def current_datetime(request):
    current_date = datetime.datetime.now()
    return render_to_response('current_datetime.html', locals())
##locals() here return {'current_data': nowtime, 'request': userRequest}


###################################################
## using django.shorcuts

# from django.shortcuts import render_to_response
# import datetime

# def current_datetime(request):
#     now = datetime.datetime.now()
#     paramDict = {
#             'current_date': now
#             }
#     return render_to_response('current_datetime.html', paramDict)



###################################################
## using get_template


# from django.http import HttpResponse
# from django.template.loader import get_template
# from django.template import Context, Template
# import datetime


# def current_datetime(request):
#     now = datetime.datetime.now()
#     t = get_template('current_datetime.html')
#     html = t.render(Context({'current_date': now}))
#     return HttpResponse(html)



####################################################
## current_datetime view that do not use get_template

# from django.http import HttpResponse
# from django.template import Context, Template
# import datetime

# def current_datatime(request):
#     new = datetime.datetime.now()
#     fd = open('/abspath/to/current_datetime.html')
#     tpl_text = fd.read()
#     fd.close()

#     t = Template(tpl_text)
#     html = t.render(Context({'current_date': now}))
#     return HttpResponse(html)
#     pass
