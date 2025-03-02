public class SpApiConfig {

    public static String getApiKey() {
        return System.getenv("SP_API_KEY");
    }
}

public class SpApiClient {

    public void fazerRequisicao() {
        String apiKey = SpApiConfig.getApiKey();
        // Lógica para fazer a requisição usando a apiKey
    }
}