#include "../builtin.h"

Context *createRequestContext(Context *context) {
	Context *requestContext = malloc(sizeof(Context));
	requestContext->mode = context->mode;
	requestContext->config = context->config;
	requestContext->database = NULL;
	requestContext->logger = malloc(sizeof(LOGGER));
	requestContext->build = context->build;
	return requestContext;
}

Context* mockContext() {
	Context *context = malloc(sizeof(Context));
	context->mode = APP_TESTING;
	context->database = NULL;
	context->logger = malloc(sizeof(LOGGER));
    context->logger->request_id = "0";
	context->logger->process_order = 0;
	return context;
}

char *findParam(char *name, char *params) {
    if (strcmp(params, "") == 0) {
        return "";
    }
    char **queryPairs = string_split(params, "&");
    int lengthPairs = length_pointer_pointer_char(queryPairs);
    for (int i=0; i<lengthPairs; i++) {
        char **pair = string_split(queryPairs[i], "=");
        if (length_pointer_pointer_char(pair) == 2) {
            if (strcmp(pair[0], name) == 0) {
                char *result = malloc(sizeof(char));
                result = pair[1];
                free(pair);
                free(queryPairs);
                return result;
            }
        }
        free(pair);
    }
    free(queryPairs);
    return "";
}

char *findParamFromUrl(char *name, char *url) {
	char **urlComponents = string_split(url, "?");
	if (length_pointer_pointer_char(urlComponents) < 2) {
		return "";
	}
	char *queryUrl = urlComponents[1];
	char **queryPairs = string_split(queryUrl, "&");
	int lengthPairs = length_pointer_pointer_char(queryPairs);
	for (int i=0; i<lengthPairs; i++) {
		char **pair = string_split(queryPairs[i], "=");
		if (length_pointer_pointer_char(pair) == 2) {
			if (strcmp(pair[0], name) == 0) {
				char *result = malloc(sizeof(char));
				result = pair[1];
				free(pair);
				free(urlComponents);
				free(queryUrl);
				free(queryPairs);
				return result;
			}
		}
		free(pair);
	}
	free(queryUrl);
	free(urlComponents);
	free(queryPairs);
	return "";
}

void freeContext(Context *context) {
	if (context->database != NULL) {
		cass_cluster_free(context->database->cluster);
		cass_session_free(context->database->session);
		free(context->database);
	}
	context->mode = 0;
	context->config = NULL;
    if (context->logger != NULL) {
       free(context->logger);
    }
	free(context);
}